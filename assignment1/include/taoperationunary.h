#ifndef TAOPERATIONUNARY_H
#define TAOPERATIONUNARY_H

#include "taoperation.h"

class TAOperationUnary: public TAOperation {
protected:
	TA& operand;
public:
	TAOperationUnary(TA& ,std::string name = "");
	virtual string generateRepresentation();
};


#endif