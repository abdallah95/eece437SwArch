#ifndef TAVAR_H
#define TAVAR_H

#include "TAFormula.h"
#include "TATerm.h"
#include "base/Settable.h"

//Represents a value holder that can be changed and set directly

class TAVar : public Settable {
	
};

//Represents the domain of a TAVar
class TADomain {
public:
	virtual bool contains(TAVar&) = 0;
	virtual TAVar* iterate() = 0;
};

//Represents a boolean value holder
class TABoolVar : public TAVar, public TAFormula {
	bool val;
public:
	TABoolVar(bool val = false);
	bool getVal();
	void setVal(bool val);
};

//Represents a number value holder
class TANumVar : public TAVar, public TATerm {

};

//Represents an array access variable; allows retrieval of the corresponding array member value and directly setting it
class TAArrayAccess : public TAVar {

};

#endif
