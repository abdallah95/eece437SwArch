#define NDEBUG
#include <assert.h>

#include "Component/TATransition.h"

TATransition::TATransition(TAComponent * pComp, TAState * pState, TAState * nState){

   assert (pComp == NULL || prevState == NULL || nextState == NULL);

   assert (prevState -> getComponent() -> getId() != nextState -> getComponent() -> getId());

   parentComponent = pComp;
   prevState = pState;
   nextState = nState;

}

void TATransition::list(ostream & os){

   os << "Transition ( " << prevState -> getName() << " , " << nextState -> getName() << " ) ";
}
