#ifndef TAOPERATIONUNARY_H
#define TAOPERATIONUNARY_H

#include "taoperation.h"

class TAOperationUnary: public TAOperation {
protected:
	TAData& operand;
public:
	TAOperationUnary(TAData& ,std::string name = "");
	virtual string generateRepresentation();
};


#endif