#ifndef TABOOL_H
#define TABOOL_H

#include "taprimitive.h"

class TABool: public TAPrimitive {
	bool val;
public:
	TABool(bool val = false);
};


#endif