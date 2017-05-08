#ifndef IFELSE_
#define IFELSE_

#include "TAStatement.h"
#include "Expression/TATerm.h"

class TAIfElseStatement : public TAAtomicStatement {

	private:

	TATerm * condition;
	TAStatement * ifStatement;
	TAStatement * elseStatement;

	public: 
	
	TAIfElseStatement (TATerm * condition, TAStatement *  s1, TAStatement * s2);

	TATerm * getCondition(){
		return condition;
	}

	TAStatement * getIfStatement(){
		return ifStatement;
	}

	TAStatement * getElseStatement(){
		return elseStatement;
	}

	virtual void evaluate();

	virtual void list(ostream & os);

	virtual bool isIfElse(){
		return true;
	}		
};

#endif
