#include "Component/TAState.h"

//Constructor
TAState::TAState(TAComponent * pComp, Trans2Label & t2l, string name) : trans2Label(t2l){

	stateId = nextId ++;    //Set to unique id then increment the static field

	//TODO assert ( pComp != NULL)
	parentComponent = pComp;
	stateName = name;
}

/** Constructs new transition (thisState, nextState) associated with port
    Updates corresponding data fields appropriately. 
    Also, assures that at most one transition (starting from current state) correspond to each port.
*/

TATransition *  TAState::addTransition (TAState * nextState, TAPort * port){

	for (int i = 0; i < nextStates.size(); i++){
		//Transition (this, nextState) already exists
		if ( nextStates[i] -> getId() == nextState -> getId())
		{
			return NULL; //Failed to create transition
		}
	}

	if (port2Trans[port] != NULL){	//port already mapped to a transition starting from this state
		return NULL;
	}

	TATransition * transition = new TATransition (parentComponent, this, nextState);

	nextStates.push_back(nextState);
	availablePorts.push_back(port);
	availableTransitions.push_back(transition);
	port2Trans[port] = transition;	

	return transition;
	
}

//Evaluates the guard of each transition label and determines which ports are ready

void TAState::evaluate(){

	readyPorts.clear();

	for (int i = 0; i < availableTransitions.size(); i++){

		TALabel * label = trans2Label[availableTransitions[i]];
		TATerm * guard = label -> getGuard();

		guard -> evaluate();
		bool gVal = guard -> getValue().getBool();

		if (gVal){
			readyPorts.push_back(label -> getPort());		
		}
	}

	//Now readyPorts contains all the ready ports	

}

void TAState::list(ostream & os){
	//TODO write list function
}


bool TAState::isPortReady(TAPort * port){

     for (int i = 0; i < readyPorts.size(); i++){
           if (readyPorts[i] -> getId() == port -> getId()){
                                        return true;
           }
     }

 return false; //Not ready

}

vector<TAPort *> TAState::getReadyPorts(){

     vector <TAPort *> clone (readyPorts);
     return clone;

}



