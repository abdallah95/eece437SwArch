#include "Expression/TAThereExists.h"


TAThereExists::TAThereExists(TAExpression* expression, TADomain* domain): expression(expression), domain(domain) {}
	
void TAThereExists::evaluate() {
	TAVar* next = 0;
	while((next=domain->iterate())!=0) {
		expression->setInput(next);
		expression->evaluate();
		bool result = ((TABoolVar*) expression->getState())->getVal();
		if(result){
			state->setVal(true);
			return;
		}
	}
	state->setVal(false);
}


TAVar* TAThereExists::getState() {
	return state;
}
