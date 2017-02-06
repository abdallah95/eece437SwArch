#ifndef TALESSTHAN_H
#define TALESSTHAN_H

#include "taoperationbinary.h"
#include "taprimitive.h"
#include "tabool.h"

class TALessThan: public TAOperationBinary, public TABool {
public:
	TALessThan(TAPrimitive&, TAPrimitive&);
};

#endif