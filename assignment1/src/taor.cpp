#include "taor.h"


TAOr::TAOr(TABool& operand_1, TABool& operand_2): TA("|"), TAOperationBinary(operand_1,operand_2,"|") {

}

string TAOr::generateRepresentation() {
	return TAOperationBinary::generateRepresentation();
}

void TAOr::evaluate() { 

}

void TAOr::printState() {

}