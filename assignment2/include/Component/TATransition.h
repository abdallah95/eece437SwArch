#pragma once

#include <TAState.h>
#include <TAComponent.h>

/**
	Represents abstraction for a state transition i.e. a tuple (prevS, nextS) where prevS and nextS are two states of the same component
*/
class TATransition {

	private:

	TAState * prevState;
	TAState * nextState;
	TAComponent * parentComponent; //Pointer to the component containing this transition
	
	public:

	TATransition(TAComponent * pComp, TAState * pState, TAState * nState);

	TAState * getPrevState(){
		return prevState;
	}

	TAState * getNextState(){
		return nextState;
	}

	TAComponent * getComponent(){
		return parentComponent;
	}

};
