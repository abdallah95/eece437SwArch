#ifndef TAXOR_H
#define TAXOR_H

#include "taoperationbinary.h"
#include "tabool.h"

class TAXor: public TAOperationBinary, public TABool {
public:
	TAXor(TABool&, TABool&);
	virtual string generateRepresentation();
	void evaluate();
	void printState();
};

#endif