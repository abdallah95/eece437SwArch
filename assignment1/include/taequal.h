#ifndef TAEQUAL_H
#define TAEQUAL_H

#include "taoperationbinary.h"
#include "taprimitive.h"
#include "tabool.h"

class TAEqual: public TAOperationBinary, public TABool {
public:
	TAEqual(TAPrimitive&, TAPrimitive&);
};

#endif