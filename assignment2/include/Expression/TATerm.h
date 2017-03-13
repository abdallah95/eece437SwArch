#ifndef TATERM_H
#define TATERM_H

#include "TAExpression.h"
#include "TAFormula.h"
#include "TAVar.h"

//Represents an expression that evaluates to a primitive Number value
//TODO TATerm should also inherit from an abstract type class, TANumber 

class TATerm : public TAExpression {

};

//Represents a constant value of a number
//TODO Also inherits from TAConstant (which perhaps does nothing but indicate that this is of constant type)

class TANumConst : public TAExpression {

};

//Represents a unary operation that evaluates to a number value
class TAUnaryOpTerm : public TAExpression {

};

//Represents a binary operation that evaluates to a number value
class TABinaryOpTerm : public TAExpression {

};

//Represents the ternary conditional expression (c) ? e1 : e2 
// TODO Add members and set/get functions

class TAConditionalOpTerm : public TAExpression {
	TAFormula& formula1;
	TATerm& term2;
	TATerm& term3;
	TABoolVar state;
public:
	TAConditionalFormula(TAFormula& e1, TATerm& e2, TATerm& e3);
	bool evaluate();
};

#endif
