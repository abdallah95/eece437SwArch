#ifndef TAOPERATION_H
#define TAOPERATION_H 

#include "tadata.h"
#include "lister.h"
#include <string>

class TAOperation: public Lister {
protected:
	std::string opName;
public:
	TAOperation(std::string name = "");
	virtual void evaluate() = 0;
	virtual void printState() = 0;
};

#endif