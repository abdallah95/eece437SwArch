#include "taequal.h"




TAEqual::TAEqual(TAInt& operand_1, TAInt& operand_2): TA("="), TAOperationBinary(operand_1,operand_2,"=") {

}

TAEqual::TAEqual(TADouble& operand_1, TADouble& operand_2): TA("="), TAOperationBinary(operand_1,operand_2,"=") {

}

string TAEqual::generateRepresentation() {
	return TAOperationBinary::generateRepresentation();
}

void TAEqual::evaluate() { 

}

void TAEqual::printState() {

}