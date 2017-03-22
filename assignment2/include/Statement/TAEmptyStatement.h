#ifndef NILSTATEMENT_
#define NILSTATEMENT_

#include "TAStatement.h"
#include <iostream>

class TAEmptyStatement {

	public:

	static TAEmptyStatement * getInstance();

	void evaluate() {}

	void list(){
		std::cout << ";" << std::endl;
	}

	virtual bool isNil(){
		return true;
	}

	private:
	
	static TAEmptyStatement * instance;

	TAEmptyStatement(){}

};

#endif
