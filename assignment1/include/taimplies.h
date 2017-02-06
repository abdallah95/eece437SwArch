#ifndef TAIMPLIES_H
#define TAIMPLIES_H

#include "taoperationbinary.h"
#include "tabool.h"

class TAImplies: public TAOperationBinary, public TABool {
public:
	TAImplies(TABool&, TABool&);
};

#endif