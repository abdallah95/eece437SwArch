#ifndef TAAND_H
#define TAAND_H

#include "taoperationbinary.h"
#include "tabool.h"

class TAAnd: public TAOperationBinary {
public:
	TAAnd(TABool&, TABool&);
};

#endif