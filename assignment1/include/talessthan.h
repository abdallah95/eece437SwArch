#ifndef TALESSTHAN_H
#define TALESSTHAN_H

#include "taoperationbinary.h"
#include "taint.h"
#include "tadouble.h"
#include "tabool.h"

class TALessThan: public TAOperationBinary, public TABool {
public:
	TALessThan(TAInt&, TAInt&);
	TALessThan(TADouble&, TADouble&);
	virtual string generateRepresentation();
	void evaluate();
	void printState();
};

#endif