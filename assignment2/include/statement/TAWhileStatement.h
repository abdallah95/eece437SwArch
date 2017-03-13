#ifndef LOOP_
#define LOOP_

#include "TAStatement.h"
#include "Expression/TAExpression.h"

class TAWhileStatement : public TAAtomicStatement {

	private:

	TAFormula * condition;
	TAStatement * body;

	public:

	TAWhileStatement (TAFormula * c, TAStatement * s){
		
		//TODO check c and s aren't NULL; throw exception otherwise

		condition = c;
		body = s;
	}

	TAFormula * getCondition(){
		return condtion;
	}

	TAStatement * getBody(){
		return body;
	}

	virtual void evaluate();

	virtual void list();

	virtual bool isLoop(){
		return true;
	}
};
