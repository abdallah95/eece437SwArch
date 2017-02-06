#ifndef TAMUL_H
#define TAMUL_H

#include "taoperationbinary.h"
#include "taprimitive.h"

class TAMul: public TAOperationBinary, public TAPrimitive {
public:
	TAMul(TAPrimitive&, TAPrimitive&);
};

#endif