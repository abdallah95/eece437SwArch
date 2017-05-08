#define NDEBUG

#include <assert.h>
#include "Component/TALabel.h"

TALabel::TALabel (TAComponent * pComp, TAPort * p, TATerm * g, TAStatement * s){

   assert (pComp != NULL && p != NULL && g != NULL && s != NULL);

   assert (pComp.hasPort(p));
 
   assert (s.isConcurList()); //If it's concurrent statement, it can be executed concurrently with other statements
 
   parentComponent = pComp;
   port = p;
   guard = g;
   statement = s;

}

void TALabel::list(ostream & os){

  os << "( " << port -> getName() << ", ";
  guard -> list(os);
  os << ", ";
  statement -> list (os);
  os << " ) " << endl;

}
