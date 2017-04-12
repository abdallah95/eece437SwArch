#pragma once

/**
	@Author: Ahmad Yasseen
	@Date: Friday, March 24, 2017
	@Description: LTS component: states, ports, transitions, labels
	
**/

#include <vector>
#include <map>

#include "Expression/TATerm.h"
#include "Statement/TAStatement.h"

#include "TAState.h"
#include "TAPort.h"
#include "TALabel.h"
#include "TATransition.h"

#include "base/Listable.h"
#include "base/Evaluable.h"
#include "base/Clonable.h"

class TAState;
class TAPort;
class TALabel;
class TATransition;

#ifndef MAP_TYPES
#define MAP_TYPES
typedef map <TATransition *, TALabel *> Trans2Label;
typedef map <TAPort *, TATransition *> Port2Trans;
#endif

class TAComponent : public Listable, public Evaluable, public Clonable <TAComponent> {

	private:

		//Static; used to ensure that unique ids are given to components
		static unsigned int currentId;
		
		//Unique id for this component
		unsigned int componentId;
		string componentName; //Optional

		TAState * startState;	//The start state 
		TAState * currentState;

		vector<TAState *> states;
		vector<TAPort *> ports;
		vector<TATransition *> transitions;
		vector<TALabel *> labels;

		Trans2Label trans2Label;

		vector <TATransition *> availableTransitions;
		vector <TAPort *> readyPorts;

	public:				

		TAComponent(string name = "");

		string getName(){
			return componentName;
		}

		unsigned int getId(){
			return componentId;
		}

		bool setStart (TAState * start);

		TAState * getStart(){
			return startState;
		}

		TAState * getCurrentState(){
			return currentState;
		}

		virtual TAComponent * clone();
	
		virtual void list(ostream & os);		

		virtual void evaluate();

		void execute(TAPort * port);

		TAState * addState (string name = "");

		TAPort *  addPort (string name = "");
	
		TATransition *  addTransition (TAState * from, TAState * to, TALabel * label);

		TALabel *  addLabel (TAPort * port, TATerm * guard, TAStatement * statement);

		bool assignLabel2Trans (TATransition * trans, TALabel * label);

		TALabel * getLabel (TATransition * trans);
				
};
