#ifndef TAOPERATIONUNARY_H
#define TAOPERATIONUNARY_H

#include "taoperation.h"

class TAOperationUnary: public TAOperation {
	TA& operand;
public:
	TAOperationUnary(TA& ,std::string name = "");
	virtual string generateRepresentation();
	virtual void list();
};


#endif