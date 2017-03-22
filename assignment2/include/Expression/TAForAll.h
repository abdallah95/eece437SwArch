#ifndef TAFORALL_H
#define TAFORALL_H

#include "TAFormula.h"
#include "TADomain.h"
#include "TABoolVar.h"

// for all formula
class TAForAll : public TAFormula {
	TAExpression* expression;
	TADomain* domain;
	TABoolVar* state;
public:
	TAForAll(TAExpression*, TADomain*);
	void evaluate();
	TAVar* getState();
};

#endif
