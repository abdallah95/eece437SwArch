#ifndef TAOPERATIONBINARY_H
#define TAOPERATIONBINARY_H

#include "taoperation.h"

class TAOperationBinary: public TAOperation {
protected:
	TAData& operand_1;
	TAData& operand_2;
public:
	TAOperationBinary(TAData&, TAData&, string name = "");
	virtual string generateRepresentation();
};


#endif