#ifndef TAAND_H
#define TAAND_H

#include "taoperationbinary.h"
#include "tabool.h"

class TAAnd: public TAOperationBinary, public TABool {
public:
	TAAnd(TABool&, TABool&);
	virtual string generateRepresentation();
	void evaluate();
	void printState();
};

#endif