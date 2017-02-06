#ifndef TADIV_H
#define TADIV_H

#include "taoperationbinary.h"
#include "taprimitive.h"

class TADiv: public TAOperationBinary, public TAPrimitive {
public:
	TADiv(TAPrimitive&, TAPrimitive&);
};

#endif