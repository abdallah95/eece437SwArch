#define NDEBUG
#include <assert.h>
#include "Statement/TAConcurrentListOfStatements.h"
#include "Statement/TAAssignStatement.h"

TAConcurrentListOfStatements::TAConcurrentListOfStatements(TAAtomicStatement * s, TAStatement * list) 
{

    //Assure they can be executed concurrently
    assert (s1 != NULL && s1 -> isAssign()); 
    assert (l != NULL);
    assert (l -> isConcurList() || l -> isAssign());

    s1 = s;
    l = list;
}

void TAConcurrentListOfStatements::list(ostream & os){
    os << "@dotogether { " << endl;
    s1 -> list(os);
    os << endl;
    l -> list(os);
    os << "}" << endl;
}

void TAConcurrentListOfStatements::evaluate(){

     evaluateExpressions();
     executeAssignments();   
}

void TAConcurrentListOfStatements::executeAssignments(){

    s1 -> evaluate();

    if (l -> isConcurList()){

        TAConcurrentListOfStatements * concurrent = dynamic_cast<TAConcurrentListOfStatements*> (l);
        concurrent -> executeAssignments();

    } else {
       l -> evaluate();
    }
}

void TAConcurrentListOfStatements::evaluateExpressions(){

   TAAssignStatement * assign = dynamic_cast<TAAssignStatement*> (s1);
   assign -> getExp() -> evaluate();

   if (l -> isConcurList()){

     TAConcurrentListOfStatements * concurrent = dynamic_cast<TAConcurrentListOfStatements*> (l);
     concurrent -> evaluateExpressions();

   } else {

     TAAssignStatement * assign2 = dynamic_cast<TAAssignStatement*> (l);
     assign2 -> getExp() -> evaluate();     

   }

}
