#pragma once

#define NDEBUG
#include <assert.h>

#include <vector>
#include <map>

#include "Component/TAComponent.h"
#include "Component/TAPort.h"
#include "Statement/TAStatement.h"
#include "Statement/TAConcurrentListOfStatements.h"
#include "Expression/TAFormula.h"
//#include "Expression/TALAnd.h"
#include "base/Evaluable.h"
#include "base/Listable.h"

/*  Represents an abstraction of an interaction between LTS components.  */

class TAInteraction : public Listable, public Evaluable {

	private:

                static unsigned int nextId;

                unsigned int interactionId;
                string interactionName;

		vector <TAComponent* > components;
		vector <TAPort* > ports;
		map <TAComponent*, TAPort*> comp2Port;	

		TAStatement * statement;
		TATerm * guard;

	public:

                //Constructor
		TAInteraction (string name = "", TAStatement * s = NULL, TATerm * g = NULL);

                virtual void list(ostream & os);

                //Determines if this interaction is 'ready' to be executed or not
                bool isReady();

                //Executes this interaction
                virtual void evaluate();

                //Implicitly adds the corresponding component
		bool addPort (TAPort * port);
	
		TAStatement * getStatement(){
			return statement;
		}

		TATerm * getGuard(){
			return guard;
		}

	        void addStatement(TAAtomicStatement * newStatement);

	        void addGuard (TATerm * newCondition);

};
