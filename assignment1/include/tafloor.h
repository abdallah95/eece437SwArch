#ifndef TAFLOOR_H
#define TAFLOOR_H

#include "taoperationunary.h"
#include "tadouble.h"

class TAFloor: public TAOperationUnary {
public:
	TAFloor(TADouble&);
};

#endif