#include "talessthan.h"

TALessThan::TALessThan(TAInt& operand_1, TAInt& operand_2): TA("<"), TAOperationBinary(operand_1,operand_2,"<") {
}


TALessThan::TALessThan(TADouble& operand_1, TADouble& operand_2): TA("<"), TAOperationBinary(operand_1,operand_2,"<") {

}

string TALessThan::generateRepresentation() {
	return TAOperationBinary::generateRepresentation();
}

void TALessThan::evaluate() { 

}

void TALessThan::printState() {

}