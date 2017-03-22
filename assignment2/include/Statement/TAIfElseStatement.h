#ifndef IFELSE_
#define IFELSE_

#include "TAStatement.h"
#include "Expression/TAFormula.h"

class TAIfElseStatement : public TAAtomicStatement {

	private:

	TAFormula * e;
	TAStatement * s1;
	TAStatement * s2;

	public: 
	
	TAIfElseStatement (TAFormula * e, TAStatement * s1, TAStatement * s2);

	TAFormula * getCondition(){
		return e;
	}

	TAStatement * getIfStatement(){
		return s1;
	}

	TAStatement * getElseStatement(){
		return s2;
	}

	virtual void evaluate();

	virtual void list();

	virtual bool isIfElse(){
		return true;
	}		
};

#endif
