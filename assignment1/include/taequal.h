#ifndef TAEQUAL_H
#define TAEQUAL_H

#include "taoperationbinary.h"
#include "taint.h"
#include "tadouble.h"
#include "tabool.h"

class TAEqual: public TAOperationBinary, public TABool {
public:
	TAEqual(TAInt&, TAInt&);
	TAEqual(TADouble&, TADouble&);
	virtual string generateRepresentation();
	void evaluate();
	void printState();
};

#endif