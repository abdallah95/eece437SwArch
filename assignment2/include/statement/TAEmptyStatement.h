#ifndef NILSTATEMENT_
#define NILSTATEMENT_

#include "TAStatement.h"

class TAEmptyStatement {

	public:

	static TAEmptyStatement * getInstance();

	void evaluate() {}

	void list(){
		cout << ";" << endl;
	}

	virtual bool isNil(){
		return true;
	}

	private:
	
	static TAEmptyStatement * instance;

	TAEmptyStatement(){}

};

#endif