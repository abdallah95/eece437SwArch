#ifndef TAOR_H
#define TAOR_H

#include "taoperationbinary.h"
#include "tabool.h"

class TAOr: public TAOperationBinary, public TABool {
public:
	TAOr(TABool&, TABool&);
};

#endif