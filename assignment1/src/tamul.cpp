#include "tamul.h"



TAMul::TAMul(TAInt& operand_1, TAInt& operand_2): TA("*"), TAOperationBinary(operand_1,operand_2,"*") {

}

TAMul::TAMul(TADouble& operand_1, TADouble& operand_2): TA("*"), TAOperationBinary(operand_1,operand_2,"*") {

}

string TAMul::generateRepresentation() {
	return TAOperationBinary::generateRepresentation();
}

void TAMul::evaluate() { 

}

void TAMul::printState() {

}