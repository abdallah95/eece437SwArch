#ifndef TATHEREEXISTS_H
#define TATHEREEXISTS_H

#include "TAFormula.h"
#include "TADomain.h"
#include "TABoolVar.h"

// there exists formula
class TAThereExists : public TAFormula {
	TAExpression* expression;
	TADomain* domain;
	TABoolVar* state;
public:
	TAThereExists(TAExpression*, TADomain*);
	void evaluate();
	TAVar* getState();
};

#endif
