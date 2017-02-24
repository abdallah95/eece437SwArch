#include "taoperationunary.h"

TAOperationUnary::TAOperationUnary(TAData& operand, string opName): TAOperation(opName), operand(operand) {
	
}

string TAOperationUnary::generateRepresentation() {
	return "(" + opName + " " + operand.generateRepresentation() + " " + ")";
}
