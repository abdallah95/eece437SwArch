#pragma once

/**
	@Author: Ahmad Yasseen
	@Date: Friday, March 24, 2017

	## Edit 1 ##

	@By: Ahmad Yasseen

	@Date: Saturday, March 25, 2017

	@Details:
	- Moved most of the logic concerning next state transition calculation from Component to State.
	- State implements the Listable and Evaluable functional interfaces
	- Enforced the existence of containing component before state instantiaion (by constructor ...)

	** Note ** 

	State cloning is hard to define in the current architecture design.
	This is mainly because to clone a specific state with all its connections, other states be cloned first.
	But this may lead to circular definitions ...

	Instead, the cloning logic will be embedded on the component level which will construct states in the new component clone
	corresponding to the current's states. Then, it would create equivalent transitions and other connections.

	####################

*/

//Forward Declarations 
class TAComponent;
class TATransition;
class TALabel;
class TAPort;

#include <vector>
#include <map>
#include "TAComponent.h"
#include "TATransition.h"
#include "TALabel.h"
//#include "TAPort.h"

#include "base/Listable.h"
#include "base/Evaluable.h"


#ifndef MAP_TYPES
#define MAP_TYPES
typedef map <TATransition *, TALabel *> Trans2Label;
typedef map <TAPort *, TATransition *> Port2Trans;
#endif

/**
	Represents the abstraction of a state in a Finite-State Machine (FSM) that is implemented by a Component
*/
class TAState : public Listable, public Evaluable {

	private:
		//Static field; incremented each time a new state instance created. Ensures unique ids are given for states
		static unsigned int nextId;

		//Unique state id assigned to this state instance
		unsigned int stateId;

		string stateName; //Optional 

		TAComponent * parentComponent; //Pointer to the component to which this state belongs

		//Map of transitions to labels of the containing component
		Trans2Label &  trans2Label;
		//Reverse map of ports to transitions
		Port2Trans port2Trans;

		vector<TAState *> nextStates; //List of states that are directly reachable from this state via a single valid transition

		vector<TATransition *> availableTransitions; //List of transitions possible from this state

		//List of ports associated with some transition in availableTransitions; they may not be ready though
		vector<TAPort *> availablePorts; 

		//List of available ports that are also ready i.e. whose transition label guard evaluates to true
		vector<TAPort *> readyPorts;
	public:

		//Constructor
		TAState(TAComponent * pComp, Trans2Label & t2l, string name = "");


		/** Constructs new transition (thisState, nextState) associated with port
		    Updates corresponding data fields appropriately. 
	            Also, assures that at most one transition (starting from current state) correspond to each port.
		*/
		TATransition *  addTransition (TAState * nextState, TAPort * port);

		//Evaluates the guard of each transition label and determines which ports are ready
		virtual void evaluate();
	
		virtual void list(ostream & os);

		bool isPortReady(TAPort * port);

		vector <TAPort *> getReadyPorts();
	
		unsigned int getId(){
			return stateId;
		}

		string getName(){
			return stateName;
		}			

		TAComponent * getComponent(){
			return parentComponent;
		}

};

