#ifndef TABOOLVAR_H
#define TABOOLVAR_H

#include "TAVar.h"
#include "TAFormula.h"

//Represents a boolean value holder
class TABoolVar : public TAVar, public TAFormula {
	bool val;
public:
	TABoolVar(bool val = false);
	bool getVal();
	void setVal(bool val);
};

#endif
