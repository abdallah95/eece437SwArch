#include "tamorethan.h"


TAMoreThan::TAMoreThan(TAInt& operand_1, TAInt& operand_2): TA(">"), TAOperationBinary(operand_1,operand_2,">") {

}

TAMoreThan::TAMoreThan(TADouble& operand_1, TADouble& operand_2): TA(">"), TAOperationBinary(operand_1,operand_2,">") {

}

string TAMoreThan::generateRepresentation() {
	return TAOperationBinary::generateRepresentation();
}

void TAMoreThan::evaluate() { 

}

void TAMoreThan::printState() {

}