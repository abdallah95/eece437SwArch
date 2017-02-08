#include "taoperationunary.h"
#include <iostream>

TAOperationUnary::TAOperationUnary(TA& operand, string name): TAOperation(name), operand(operand) {
	
}

string TAOperationUnary::generateRepresentation() {
	return "(" + name + " " + operand.generateRepresentation() + " " + ")";
}

void TAOperationUnary::list() {
	cout << generateRepresentation() << endl;
}