#include "taoperationunary.h"

TAOperationUnary::TAOperationUnary(TA& operand, string name): TAOperation(name), operand(operand) {
	
}

string TAOperationUnary::generateRepresentation() {
	return "(" + name + " " + operand.generateRepresentation() + " " + ")";
}
