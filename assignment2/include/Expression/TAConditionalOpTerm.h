#ifndef TACONDITIONALOPTERM_H
#define TACONDITIONALOPTERM_H

#include "TATerm.h"
#include "TABool.h"

//Represents the ternary conditional expression (c) ? e1 : e2 
// TODO Add members and set/get functions

class TAConditionalOpTerm : public TATerm {
	TATerm& formula1;
	TATerm& term2;
	TATerm& term3;
public:
	TAConditionalOpTerm(TATerm& formula1, TATerm& term2, TATerm& term3)
	:formula1(formula1), term2(term2), term3(term3){}
	virtual TAValue& evaluateExecute(TATerm& formula1, TATerm& term2, TATerm& term3);
};

#endif
