#include "taadd.h"

TAAdd::TAAdd(TAInt& operand_1, TAInt& operand_2): TA("+"), TAOperationBinary(operand_1,operand_2,"+") {

}

TAAdd::TAAdd(TADouble& operand_1, TADouble& operand_2): TA("+"), TAOperationBinary(operand_1,operand_2,"+") {

}

string TAAdd::generateRepresentation() {
	return TAOperationBinary::generateRepresentation();
}

void TAAdd::evaluate() {

}

void TAAdd::printState() {

}