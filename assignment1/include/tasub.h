#ifndef TASUB_H
#define TASUB_H

#include "taoperationbinary.h"
#include "taprimitive.h"

class TASub: public TAOperationBinary {
public:
	TASub(TAPrimitive&, TAPrimitive&);
};

#endif