#pragma once

#include "base/Listable.h"
#include "Statement/TAStatement.h"
#include "Expression/TATerm.h"
#include "TAPort.h"
#include "TAComponent.h"

/*
 	Represents an abstraction of a transition label which is a tuple (Guard, port, action):
         - Guard: The condition for a transition to be valid (b/w two states).
	 - Action: statement(s) to be executed when the transition is to take place.
*/

class TALabel : Listable {

	private:

		TAComponent * parentComponent;

		TAPort * port;
		TATerm * guard;
		TAStatement * statement;

	public:

		TALabel (TAComponent * pComp, TAPort * p, TATerm * g, TAStatement * s);

                virtual void list(ostream & os);

		TAComponent * getComponent(){
			return parentComponent;
		}		

		TAPort * getPort(){
			return port;
		}

		TATerm * getGuard(){
			return guard;
		}

		TAStatement * getStatement(){
			return statement;
		}
};
