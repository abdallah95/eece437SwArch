#ifndef SEQSTATEMENTLIST_
#define SEQSTATEMENTLIST_

#include "TAStatement.h"

class TASeqListOfStatements : public TAStatement {

	private:

	TAAtomicStatement * s1;
	TAStatement * l;

	public:

	TASeqListOfStatements (TAAtomicStatement * s, TAStatement * list);

	virtual void evaluate();

	virtual void list();
	
	virtual bool isList(){
		return true;
	}

	virtual bool isSeqList(){
		return true;
	}
}
 
#endif
