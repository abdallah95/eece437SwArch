#ifndef TACONDITIONALFORMULA_H
#define TACONDITIONALFORMULA_H


#include "TATerm.h"
#include "TABool.h"

//Represents the ternary conditional (c) ? e1 : e2 
//TODO Add members ...

class TAConditionalFormula : public TATerm {
	TATerm& formula1;
	TATerm& formula2;
	TATerm& formula3;
public:
	TAConditionalFormula(TATerm& formula1, TATerm& formula2, TATerm& formula3)
	:formula1(formula1), formula2(formula2), formula3(formula3) {}
	virtual TAValue& evaluateExecute(TATerm& formula1, TATerm& formula2, TATerm& formula3);
};


#endif
