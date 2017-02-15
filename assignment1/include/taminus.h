#ifndef TAMINUS_H
#define TAMINUS_H

#include "taoperationunary.h"
#include "taint.h"
#include "tadouble.h"

class TAMinus: public TAOperationUnary, public TADouble {
public:
	TAMinus(TAInt&);
	TAMinus(TADouble&);
	virtual string generateRepresentation();
	void evaluate();
	void printState();
};

#endif