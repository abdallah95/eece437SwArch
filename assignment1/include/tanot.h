#ifndef TANOT_H
#define TANOT_H

#include "taoperationunary.h"
#include "tabool.h"

class TANot: public TAOperationUnary, public TABool {
public:
	TANot(TABool&);
};

#endif