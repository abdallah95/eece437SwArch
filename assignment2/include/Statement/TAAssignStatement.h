#ifndef ASSIGNMENT_
#define ASSIGNMENT_

#include "TAStatement.h"
#include "Expression/TAVar.h"
#include "Expression/TAExpression.h"

class TAAssignStatement : public TAAtomicStatement {

	private:
	
	TAVar * target;
	TAExpression * exp;

	public:

	TAAssignStatement (TAVar * t, TAExpression * e);
	
	TAVar * getTarget(){
		return target;
	}

	TAExpression * getExp(){
		return exp;
	}

	virtual void evaluate();

	virtual void list();

	virtual bool isAssign(){
		return true;
	}
};

#endif
