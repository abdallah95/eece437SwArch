#ifndef TAOPERATIONUNARY_H
#define TAOPERATIONUNARY_H

#include "taoperation.h"

class TAOperationUnary: public TAOperation {
	TA& operand;
public:
	TAOperationUnary(TA&);
};


#endif