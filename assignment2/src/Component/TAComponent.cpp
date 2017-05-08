#define NDEBUG
#include <assert.h>

#include <stdlib.h>
#include "Component/TAComponent.h"

unsigned int TAComponent::currentId = 0; 

//Constructor
TAComponent::TAComponent (string name){
		componentName = name;
		componentId = currentId ++;
}

bool TAComponent::setStart(TAState * start){

	assert (start != NULL);
	assert (start -> getComponent() -> getId() == getId());
	startState = start; 
}

TAComponent * TAComponent::clone(){

        //New component
	TAComponent * newClone = new TAComponent(this -> componentName);
	
        //Helper maps
	map <TAState *, TAState *> state2state;          //Maps old states to their corresp. clones
	map <TAPort *, TAPort *> port2port;              //Maps old ports to their corresp. clones
        map <TALabel *, TALabel *> label2label;          //Maps old labels to their corresp. clones

        //Clone all states (but don't fill yet)
        for (unsigned int i = 0; i < states.size(); i++){

               TAState * state = states[i];
               assert(state != NULL);
               TAState * newState = newClone -> addState(state -> getName());
               assert (newState != NULL);
               state2state[state] = newState;
        }

        //Clone all ports 
        for (unsigned int j = 0; j < ports.size(); j++){
           
               TAPort * port = ports[j];
               assert (port != NULL);
               
               TAPort * newPort = newClone -> addPort(port -> getName());
               assert (newPort != NULL);

               port2port[port] = newPort;
        }

        for (unsigned int k = 0; k < labels.size(); k++){
             
               TALabel * label = labels[k];
               assert (label != NULL);

               //TODO Clone variables in the guard and action statement 
               //TODO Then, clone guard and action and use the new copies

               TATerm * newGuard = label -> getGuard(); //TODO Use clone instead
               assert (newGuard != NULL);

               TAStatement * newStatement = label -> getStatement(); //TODO Use clone instead
               assert(newStatement != NULL);

               TAPort * newPort = port2port[label -> getPort()];
               assert (newPort != NULL);

               TALabel * newLabel = newClone -> addLabel(newPort, newGuard, newStatement);
               assert (newLabel != NULL);
 
               label2label[label] = newLabel;               
        }

        for (unsigned int l = 0; l < transitions.size(); l++){
         
               TATransition * transition = transitions[l];
               assert (transition != NULL);

               TAState * from = state2state[transition -> getPrevState()];
               assert(from != NULL);

               TAState * to = state2state[transition -> getNextState()];
               assert(to != NULL);

               TALabel * label = getLabel(transition);
               assert(label != NULL);
               label = label2label[label];
               assert (label != NULL);

               TATransition * newTransition = newClone -> addTransition(from, to, label);
               assert (newTransition != NULL);
        }

	return newClone;	
}


void TAComponent::list(ostream & os){

	os << "Component " << getName() << " of Id = " << getId() << " { " << endl;

        os << "States: ";
        for (unsigned int i = 0; i < states.size(); i++){
              os << states[i] -> getName() <<  ", ";
        }
        os << endl;

        os << "Ports: ";
        for (unsigned int j = 0; j < ports.size(); j++){
              os << ports[j] -> getName() << ", ";
        }
        os << endl;

        os << "Transitions: ";
        for (unsigned int k = 0; k < transitions.size(); k++){
             transitions[k] -> list(os);
             os << " with label ";
             getLabel(transitions[k]) -> list(os);
             os << endl;
        }
        os << endl;
}

void TAComponent::evaluate(){

	time_t t;

	srand((unsigned) time(&t));

	currentState -> evaluate();
	vector <TAPort *> readyPorts = currentState -> getReadyPorts();
	
	if (readyPorts.empty()){
		return;
	} 

	if (readyPorts.size() == 1){
		execute (readyPorts[0]);
		return;
	}

	//Select one of the ports non-deterministically
	int selected = rand() % readyPorts.size(); 
	TAPort * selectedPort = readyPorts[selected];

	execute (selectedPort);
	
}

//Executes the transition corresponding with this port
void TAComponent::execute(TAPort * port){

  assert (currentState -> isPortReady(port));
  
  TATransition * transition = currentState -> getTransition(port);
  assert (transition != NULL);

  TALabel * label = trans2Label[transition];
  assert (label != NULL);
  
  label -> getStatement() -> evaluate(); //Execute action statement
  
  currentState = transition -> getNextState();

}

TAState * TAComponent::addState (string name){
	TAState * state = new TAState(this, trans2Label, name);
	assert(state != NULL);
	states.push_back(state);

	return state;
}

TAPort *  TAComponent::addPort (string name){
	TAPort * port = new TAPort (this, name);
	assert(port != NULL);
	ports.push_back(port);

	return port;
}

//We assume that every transition should be assigned 
TATransition *  TAComponent::addTransition (TAState * from, TAState * to, TALabel * label){
	
        TATransition * transition = from -> addTransition(to, label -> getPort());
	assert(transition != NULL);

	transitions.push_back(transition);
	
	trans2Label[transition] = label;

	return transition;
}

TALabel *  TAComponent::addLabel (TAPort * port, TATerm * guard, TAStatement * statement){

	TALabel * label = new TALabel (this, port, guard, statement);
	labels.push_back(label);

	return label;
}

TALabel * TAComponent::getLabel (TATransition * trans){
	return trans2Label[trans];
}
