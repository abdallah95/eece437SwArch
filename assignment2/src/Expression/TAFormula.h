#include "TAExpression.h"

//Represents an expression that evaluates to a Boolean value {True, False}
//TODO Should also inherit from a type class, TABool (not implemented yet)

class TAFormula : public TAExpression {
		
};

//Represents a constant of the boolean type 
//TODO should also inherit from TAConstant
//TODO Consider if we should instantiate only two instances of this class (SINGLETON PATTERN ??)

class TABoolConst : public TAExpression {

};

class TAUnaryOpFormula : public TAFormula {

};

class TABinaryOpFormula : public TAFormula {

};

//Represents the ternary conditional (c) ? e1 : e2 
//TODO Add members ...

class TAConditionalFormula : public TAFormula {

};


