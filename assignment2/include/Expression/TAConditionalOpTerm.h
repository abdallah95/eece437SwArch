#ifndef TACONDITIONALOPTERM_H
#define TACONDITIONALOPTERM_H

#include "TAExpression.h"
#include "TABoolVar.h"
#include "TATerm.h"

//Represents the ternary conditional expression (c) ? e1 : e2 
// TODO Add members and set/get functions

class TAConditionalOpTerm : public TAExpression {
	TAFormula* formula1;
	TATerm* term2;
	TATerm* term3;
	TABoolVar* state;
public:
	TAConditionalOpTerm(TAFormula* e1, TATerm* e2, TATerm* e3);
	void evaluate();
};

#endif
