#ifndef TAFLOOR_H
#define TAFLOOR_H

#include "taoperationunary.h"
#include "tadouble.h"
#include "taint.h"

class TAFloor: public TAOperationUnary, public TAInt {
public:
	TAFloor(TADouble&);
	virtual string generateRepresentation();
	void evaluate();
	void printState();
};

#endif