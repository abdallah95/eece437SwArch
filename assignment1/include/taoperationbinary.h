#ifndef TAOPERATIONBINARY_H
#define TAOPERATIONBINARY_H

#include "taoperation.h"

class TAOperationBinary: public TAOperation {
protected:
	TA& operand_1;
	TA& operand_2;
public:
	TAOperationBinary(TA&, TA&, string name = "");
	virtual string generateRepresentation();
};


#endif