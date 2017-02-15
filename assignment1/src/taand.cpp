#include "taand.h"


TAAnd::TAAnd(TABool& operand_1, TABool& operand_2): TA("&"), TAOperationBinary(operand_1,operand_2,"&") {

}

string TAAnd::generateRepresentation() {
	return TAOperationBinary::generateRepresentation();
}

void TAAnd::evaluate() { 

}

void TAAnd::printState() {

}