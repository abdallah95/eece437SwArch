#ifndef TAMINUS_H
#define TAMINUS_H

#include "taoperationunary.h"
#include "taprimitive.h"

class TAMinus: public TAOperationUnary, public TAPrimitive {
public:
	TAMinus(TAPrimitive&);
};

#endif