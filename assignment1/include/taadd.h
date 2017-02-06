#ifndef TAADD_H
#define TAADD_H

#include "taoperationbinary.h"
#include "taprimitive.h"

class TAAdd: public TAOperationBinary {

//	static const TAAdd taadd_type;

public:
	TAAdd(TAPrimitive&, TAPrimitive&);
};

#endif