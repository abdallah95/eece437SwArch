#include "Expression/TAForAll.h"


TAForAll::TAForAll(TAExpression* expression, TADomain* domain): expression(expression), domain(domain) {}

void TAForAll::evaluate() {
	TAVar* next = 0;
	while((next=domain->iterate())!=0) {
		expression->setInput(next);
		expression->evaluate();
		bool result = ((TABoolVar*) expression->getState())->getVal();
		if(!result){
			state->setVal(false);
			return;
		}
	}
	state->setVal(true);
}

TAVar* TAForAll::getState() {
	return state;
}
