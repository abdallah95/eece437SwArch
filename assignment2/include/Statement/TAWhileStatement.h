#ifndef LOOP_
#define LOOP_

#include "TAStatement.h"
#include "Expression/TATerm.h"

#include "Expression/TATerm.h"

class TAWhileStatement : public TAAtomicStatement {

	private:

	TATerm * condition;
	TAStatement * body;

	public:

	TAWhileStatement (TATerm * condition, TAStatement * body);

	TATerm * getCondition(){
		return condition;
	}

	TAStatement * getBody(){
		return body;
	}

	virtual void evaluate();

	virtual void list(ostream & os);

	virtual bool isLoop(){
		return true;
	}
};

#endif
