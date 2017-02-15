#ifndef TAMORETHAN_H
#define TAMORETHAN_H

#include "taoperationbinary.h"
#include "taint.h"
#include "tadouble.h"
#include "tabool.h"

class TAMoreThan: public TAOperationBinary, public TABool {
public:
	TAMoreThan(TAInt&, TAInt&);
	TAMoreThan(TADouble&, TADouble&);
	virtual string generateRepresentation();
	void evaluate();
	void printState();
};

#endif