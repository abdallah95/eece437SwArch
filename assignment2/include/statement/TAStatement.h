#ifndef STATEMENT_
#define STATEMENT_

/**
	Represents a statement that can be evaluated i.e. executed.
*/

class TAStatement : public Evaluable, public Listable {

	public:

	virtual bool isStatement(){
		return true;
	}

	virtual bool isAtomic(){
		return false;
	}

	virtual bool isAssign(){
		return false;
	}

	virtual bool isIfElse(){
		return false;
	}

	virtual bool isLoop(){
		return false;
	}

	virtual bool isNil(){
		return false;
	}

	virtual bool isList(){
		return false;
	}

	virtual bool isSeqList(){
		return false;
	}

	virtual bool isConcurList(){
		return false;
	}

};

//Represents an atomic statement i.e. assignment, conditionl or loop statement.

class TAAtomicStatement : public TAStatement {

	public:

	virtual bool isAtomic(){
		return true;
	}

};
#endif
