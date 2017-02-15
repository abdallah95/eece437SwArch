#ifndef TAADD_H
#define TAADD_H

#include "taoperationbinary.h"
#include "taint.h"
#include "tadouble.h"

class TAAdd: public TAOperationBinary, public TADouble {

public:
	TAAdd(TAInt&, TAInt&);
	TAAdd(TADouble&, TADouble&);
	virtual string generateRepresentation();
	void evaluate();
	void printState();
};

#endif