#ifndef TAOPERATIONBINARY_H
#define TAOPERATIONBINARY_H

#include "taoperation.h"

class TAOperationBinary: public TAOperation {
	TA& operand_1;
	TA& operand_2;
public:
	TAOperationBinary(TA&, TA&);
};


#endif