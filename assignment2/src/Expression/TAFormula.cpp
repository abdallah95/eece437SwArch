#include "Expression/TAFormula.h"

TAForAll::TAForAll(TAExpression& expression, TADomain& domain): expression(expression), domain(domain) {}

bool TAForAll::evaluate() {
	TAVar* next = NULL;
	while((next=domain.iterate())!=NULL) {
		expression.setInput(*next);
		expression.evaluate();
		bool result = ((TABoolVar) expression.getState()).getVal();
		if(!result){
			state.setVal(false);
			return;
		}
	}
	state.setVal(true);
}

TAVar TAForAll::getState() {
	return state;
}


TAThereExists::TAThereExists(TAExpression& expression, TADomain& domain): expression(expression), domain(domain) {}
	
void TAThereExists::evaluate() {
	TAVar* next = NULL;
	while((next=domain.iterate())!=NULL) {
		expression.setInput(*next);
		expression.evaluate();
		bool result = ((TABoolVar) expression.getState()).getVal();
		if(result){
			state.setVal(true);
			return;
		}
	}
	state.setVal(false);
}


TAVar TAThereExists::getState() {
	return state;
}

TAConditionalFormula::TAConditionalFormula(TAFormula& e1, TAFormula& e2, TAFormula& e3)
	: formula1(e1), formula2(e2), formula3(e3) {}

void TAConditionalFormula::evaluate() {
	bool f1val = ((TABoolVar) formula1.getState()).getVal();
	bool f2val = ((TABoolVar) formula2.getState()).getVal();
	bool f3val = ((TABoolVar) formula3.getState()).getVal();
	state.setVal(f1val ? f2val:f3val);
}


TAVar TAConditionalFormula::getState() {
	return state;
}
