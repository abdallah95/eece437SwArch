#ifndef TACONDITIONALFORMULA_H
#define TACONDITIONALFORMULA_H


#include "TAFormula.h"
#include "TABoolVar.h"

//Represents the ternary conditional (c) ? e1 : e2 
//TODO Add members ...

class TAConditionalFormula : public TAFormula {
	TAFormula* formula1;
	TAFormula* formula2;
	TAFormula* formula3;
	TABoolVar* state;
public:
	TAConditionalFormula(TAFormula* e1, TAFormula* e2, TAFormula* e3);
	void evaluate();
	TAVar* getState();
};


#endif
