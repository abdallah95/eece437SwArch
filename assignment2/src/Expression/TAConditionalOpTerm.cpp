#include "Expression/TAConditionalOpTerm.h"


TAConditionalOpTerm::TAConditionalOpTerm(TAFormula* e1, TATerm* e2, TATerm* e3)
: formula1(e1), term2(e2), term3(e3) {}

void TAConditionalOpTerm::evaluate() {
	bool f1state = ((TABoolVar*) formula1->getState())->getVal();
	TAVar* t2state = term2->getState();
	TAVar* t3state = term3->getState();

	state = (TABoolVar*)(f1state ? t2state:t3state);
}