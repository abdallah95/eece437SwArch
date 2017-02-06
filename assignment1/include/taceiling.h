#ifndef TACEILING_H
#define TACEILING_H

#include "taoperationunary.h"
#include "tadouble.h"

class TACeiling: public TAOperationUnary, public TADouble {
public:
	TACeiling(TADouble&);
};

#endif