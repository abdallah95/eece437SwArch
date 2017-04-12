#ifndef TADOMAIN_H
#define TADOMAIN_H

#include "TAValue.h"
#include <Expression/TANamedObj.h>

//Represents the domain of a TAValue
class TADomain: public TANamedObj {
public:
	TADomain(const string& s): TANamedObj(s) {}
	virtual bool contains(TAValue&) = 0;
	virtual TAValue* iterate() = 0;
};


#endif
