#ifndef TAINT_H
#define TAINT_H

#include "taprimitive.h"

class TAInt: public TAPrimitive {
	int val;
public:
	TAInt(int val = 0);
};


#endif