#ifndef CONCURRENT_
#define CONCURRENT_

#include "Statement.h"
#include "Expression.h"

class TAConcurrentListOfStatements : public Statement {

	private:

	TAAtomicStatement * s1;
	TAStatement * l;

	
	public:

	TAConcurrentListOfStatements (TAAtomicStatement *s, TAStatement *list){
			
			s1 = s;

			l = list;
	}

	virtual void list();
	
	virtual void evaluate();

	virtual void isList(){
		return true;
	}

	virtual void isConcurList(){
		return true;
	}
};

#endif
