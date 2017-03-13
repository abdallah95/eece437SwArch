#ifndef ASSIGNMENT_
#define ASSIGNMENT_

#include "TAStatement.h"
#include "Expression/TAVar.h"

class TAAssignmentStatement : public TAAtomicStatement {

	private:
	
	TAVar * target;
	TAExpression * exp;

	public:

	TAAssignmentStatement (TAVar * t, TAExpression * e);
	
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
