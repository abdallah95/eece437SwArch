#include <stdlib.h>
#include "Component/TAComponent.h"

//Constructor
TAComponent::TAComponent (string name){
		componentName = name;
		componentId = currentId ++;
}

bool TAComponent::setStart(TAState * start){

	//TODO assert (start != NULL);
	//TODO assert (start -> getComponent() -> getId() -= getId());
	startState = start; //Assuming the start state can be changed TODO Recheck this decision
}

TAComponent * TAComponent::clone(){

	TAComponent * newClone = new TAComponent(this -> componentName);
	
	map <TAState *, TAState *> state2state;
	map <TAPort *, TAPort *> port2port;
	map <TATransition *, TATransition *> tran2tran;

	//TODO continue ...

	return NULL;	
}


void TAComponent::list(ostream & os){

	//TODO List ...
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

void TAComponent::execute(TAPort * port){

}

TAState * TAComponent::addState (string name){
	TAState * state = new TAState(this, trans2Label, name);
	//TODO assert(state != NULL);
	states.push_back(state);

	return state;
}

TAPort *  TAComponent::addPort (string name){
	TAPort * port = new TAPort (this, name);
	//TODO assert(port != NULL);
	ports.push_back(port);

	return port;
}

//We assume that every transition should be assigned 
TATransition *  TAComponent::addTransition (TAState * from, TAState * to, TALabel * label){
	TATransition * transition = from -> addTransition(to, label -> getPort());
	//TODO assert(transition != NULL);
	transitions.push_back(transition);
	
	//TODO Check that label is in labels; if not, add it ?

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
