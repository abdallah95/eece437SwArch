#ifndef TADOMAIN_H
#define TADOMAIN_H

#include "TAVar.h"

//Represents the domain of a TAVar
class TADomain {
public:
	virtual bool contains(TAVar&) = 0;
	virtual TAVar* iterate() = 0;
};


#endif
