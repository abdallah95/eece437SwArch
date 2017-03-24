#include <TATransition.h>

TATransition::TATransition(TAComponent * pComp, TAState * pState, TAState * nState){

   if (pComp == NULL || prevState == NULL || nextState == NULL){
      throw -1; //Arbitrary exception (TODO Define and handle exceptions in a more systematic, consistent manner)
   }

   //TODO Check if direct pointer comparison works OR replace with comparing component ids
   if (prevState -> getComponent() != nextState -> getComponent()){
      throw -2; //TODO Handle Exceptions more systematically
   }

   parentComponent = pComp;
   prevState = pState;
   nextState = nState;

}
