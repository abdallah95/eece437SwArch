#ifndef TAXOR_H
#define TAXOR_H

#include "taoperationbinary.h"
#include "tabool.h"

class TAXor: public TAOperationBinary {
public:
	TAXor(TABool&, TABool&);
};

#endif