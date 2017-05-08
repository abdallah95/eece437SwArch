#ifndef SEQSTATEMENTLIST_
#define SEQSTATEMENTLIST_

#include "TAStatement.h"

// Represents a sequence of statements that should be executed sequentially (may include concurrent list of statements though)

class TASeqListOfStatements : public TAStatement {

	private:

	TAAtomicStatement * s1;
	TAStatement * l;

	public:

	TASeqListOfStatements (TAAtomicStatement * s, TAStatement * list);

	virtual void evaluate();

	virtual void list(ostream & os);
	
	virtual bool isList(){
		return true;
	}

	virtual bool isSeqList(){
		return true;
	}
};
 
#endif
