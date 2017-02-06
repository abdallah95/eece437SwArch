#ifndef TADOUBLE_H
#define TADOUBLE_H

#include "taprimitive.h"

class TADouble: public TAPrimitive {
	double val;
public:
	TADouble(double val = 0);
};


#endif