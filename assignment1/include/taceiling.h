#ifndef TACEILING_H
#define TACEILING_H

#include "taoperationunary.h"
#include "tadouble.h"
#include "taint.h"

class TACeiling: public TAOperationUnary, public TAInt {
public:
	TACeiling(TADouble&);
};

#endif