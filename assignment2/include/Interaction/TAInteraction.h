#pragma once

#define NDEBUG
#include <assert.h>

#include <vector>
#include <map>

#include "Component/TAComponent.h"
#include "Component/TAPort.h"
#include "Statement/TAStatement.h"
#include "Expression/Formula.h"
#include "base/Evaluable.h"
#include "base/Listable.h"

class TAInteraction : public Listable, public Evaluable {

	private:
//		vector <TAComponent* > components;
		vector <TAPort* > ports;
		map <TAComponent*, TAPort*> comp2Port;	

		TAStatement * statement;
		TAFormula * guard;

	public:

		TAInteraction (TAStatement * s = NULL, TAFormula * g = NULL){

			statement = s;
			guard = g;	
		}


		bool addPort (TAPort * port){

                      	assert (port != NULL && port -> getComponent() != NULL);
			TAComponent * component = port -> getComponent();
			
			if (comp2Port[component] != NULL){
				return false;
			}

			comp2Port[component] = port;
			ports.push_back(port);

			return true;
		}
		
		TAStatement * getStatement(){
			return statement;
		}

		TAFormula * getGuard(){
			return guard;
		}

		#if 0
			void addStatement(TAAtomicStatement * newStatement){
			
				if (statement == NULL){
					statement = newStatement;
					return;
				}

				if (newStatement == NULL){
					return;
				}
\					
				if (newStatement -> isLoop() ||newStatement -> isConditional()){
					return;
				}
				statement = new ConcurrentListOfStatements(newStatement, statement);
			}

			void addGuard (TAFormula * newCondition){
				if (newCondition == NULL){
					return;
				}

				if (guard == NULL){
					guard = newCondtion;
					return;
				}

				guard = new And(guard, newCondition);
			}	
		#endif

		
};
