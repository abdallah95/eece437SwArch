#define NDEBUG
#include <assert.h>
#include "Component/TAState.h"
#include <sstream>

//Initialize static field 
unsigned int TAState::nextId = 0;

//Constructor
TAState::TAState(TAComponent * pComp, Trans2Label & t2l, string name) : trans2Label(t2l){

	stateId = nextId ++;    //Set to unique id then increment the static field

	assert ( pComp != NULL);

	parentComponent = pComp;
        
        if (name == ""){

            stringstream ss;
            ss << "s" << stateId;
            stateName = ss.str();

        } else {

          stateName = name;

        }

}

/** Constructs new transition (thisState, nextState) associated with port
    Updates corresponding data fields appropriately. 
    Also, assures that at most one transition (starting from current state) correspond to each port.
*/

TATransition *  TAState::addTransition (TAState * nextState, TAPort * port){

	for (int i = 0; i < nextStates.size(); i++){
		//Transition (this, nextState) already exists
		if ( nextStates[i] -> getId() == nextState -> getId() ) {

                        //Error message
                        cerr << "Cannot create multiple transitions from  ";
                        list(cerr);
                        cerr << " to ";
                        nextState -> list (cerr);

			return NULL; //Failed to create transition
		}
	}

	if (port2Trans[port] != NULL){	//port already mapped to a transition starting from this state
    
                //Error message
                cerr << "Cannot associate port " << port -> getId() << "with more than one transitions out from  ";
                list (cerr); 
                cerr << endl;
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

	readyPorts.clear(); //Clear for refilling 

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
	os << "State " << getName() << " of Id = " << getId() << endl;

// TODO Decide whether to list state info in detail or not
 
#if 0   
        os << " { " << endl;

        // Print all ports of transitions from here
        os << "Ports : " << endl;
        for (unsigned int i = 0; i < availablePorts.size(); i++){
               TAPort * port = availablePorts[i];
               os << "Port " << port -> getName() << " of Id = " << port -> getId() << endl;
        }

       //Print all next states (names)
       os << "Next States: " << endl;
       for (unsigned int j = 0; j < nextStates.size(); j++){
             TAState * state = nextStates[j];
             os << "State " << state -> getName() << " of Id = " << state -> getId() << endl;
       }

       //Print all transitions from here with their labels
       os << "Available Transitions: " << endl;
       for (unsigned int k = 0; k < availableTransitions.size(); k++){
            TATransition * transition = availableTransitions[k];
            transition -> list(os);
       }

       os << " } " << endl;
#endif 

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

     //Clone and return (to prevent illegal external modification)
     vector <TAPort *> clone (readyPorts);
     return clone;

}



