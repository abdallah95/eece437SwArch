#ifndef TASUB_H
#define TASUB_H

#include "taoperationbinary.h"
#include "taint.h"
#include "tadouble.h"

class TASub: public TAOperationBinary, public TADouble {
public:
	TASub(TAInt&, TAInt&);
	TASub(TADouble&, TADouble&);
};

#endif