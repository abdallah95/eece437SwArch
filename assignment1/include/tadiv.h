#ifndef TADIV_H
#define TADIV_H

#include "taoperationbinary.h"
#include "taint.h"
#include "tadouble.h"

class TADiv: public TAOperationBinary, public TADouble {
public:
	TADiv(TAInt&, TAInt&);
	TADiv(TADouble&, TADouble&);
};

#endif