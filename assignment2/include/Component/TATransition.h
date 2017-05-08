#pragma once

#include "base/Listable.h"
#include "TAState.h"
#include "TAComponent.h"
#include "TALabel.h"
#include "TAPort.h"

//TODO Consider implementing list method 

class TAState;
class TAComponent;

/* Represents abstraction for a state transition i.e. a tuple (prevS, nextS) where prevS and nextS are two states of the same component */

class TATransition : Listable {

	private:

	TAState * prevState;
	TAState * nextState;
	TAComponent * parentComponent; //Pointer to the component containing this transition
	
	public:

	TATransition(TAComponent * pComp, TAState * pState, TAState * nState);

        virtual void list(ostream & os);

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
