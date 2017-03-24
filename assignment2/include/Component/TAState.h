#pragma once

/**
	@Author: Ahmad Yasseen
	@Date: Friday, March 24, 2017
*/

#include <vector>
#include <TAComponent.h>
#include <TATransition.h>

/**
	Represents the abstraction of a state in a Finite-State Machine (FSM) that is implemented by a Component
*/
class TAState {

	private:
		static unsigned int nextId;

		unsigned int stateId;

		String stateName; //Optional 

		TAComponent * parentComponent; //Pointer to the component to which this state belongs

		vector<TAState *> nextStates; //List of states that are directly reachable from this state via a single valid transition

	public:

		TAState(TAComponent * pComp, String name = ""){

			stateId = nextId ++;	//Set to unique id then increment the static field
			parentComponent = pComp;
			stateName = name;
		}

		//Adds a new next state i.e. a state that is directly reachable from this state via one valid transition
		//Returns true if successful, false otherwise (in particular, if the new state is already in the nextStates vector.

		bool addNextState(TAState * newState);

		unsigned int getId(){
			return stateId;
		}

		String getName(){
			return stateName;
		}			

		TAComponent * getComponent(){
			return parentComponent;
		}
};

