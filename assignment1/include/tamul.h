#ifndef TAMUL_H
#define TAMUL_H

#include "taoperationbinary.h"
#include "taint.h"
#include "tadouble.h"

class TAMul: public TAOperationBinary, public TADouble {
public:
	TAMul(TAInt&, TAInt&);
	TAMul(TADouble&, TADouble&);
	virtual string generateRepresentation();
	void evaluate();
	void printState();
};

#endif