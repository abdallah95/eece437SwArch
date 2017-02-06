#ifndef TAMORETHAN_H
#define TAMORETHAN_H

#include "taoperationbinary.h"
#include "taprimitive.h"

class TAMoreThan: public TAOperationBinary, public TAPrimitive {
public:
	TAMoreThan(TAPrimitive&, TAPrimitive&);
};

#endif