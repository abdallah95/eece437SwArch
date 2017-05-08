#ifndef ASSIGNMENT_
#define ASSIGNMENT_

#include "TAStatement.h"
#include "Expression/TAValue.h"
#include "Expression/TATerm.h"
#include <Expression/TANamedObj.h>

class TAAssignStatement : public TAAtomicStatement {

	private:
	
	TANamedObj * target;
	TATerm  * exp;

	public:

	TAAssignStatement (TANamedObj * , TATerm *);
	
	TANamedObj * getTarget(){
		return target;
	}

	TATerm * getExp(){
		return exp;
	}

	virtual void evaluate();

	virtual void list(ostream & os);

	virtual bool isAssign(){
		return true;
	}
};

#endif
