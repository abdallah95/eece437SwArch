#include "Expression/TAConditionalFormula.h"


TAConditionalFormula::TAConditionalFormula(TAFormula* e1, TAFormula* e2, TAFormula* e3)
	: formula1(e1), formula2(e2), formula3(e3) {}

void TAConditionalFormula::evaluate() {
	bool f1val = ((TABoolVar*) formula1->getState())->getVal();
	bool f2val = ((TABoolVar*) formula2->getState())->getVal();
	bool f3val = ((TABoolVar*) formula3->getState())->getVal();
	state->setVal(f1val ? f2val:f3val);
}


TAVar* TAConditionalFormula::getState() {
	return state;
}
