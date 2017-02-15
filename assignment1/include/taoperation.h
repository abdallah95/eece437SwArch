#ifndef TAOPERATION_H
#define TAOPERATION_H 

#include "ta.h"

class TAOperation: public virtual TA {
public:
	TAOperation(string name = "");
	virtual void evaluate() = 0;
	virtual void printState() = 0;
};

#endif