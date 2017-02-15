#include "taxor.h"


TAXor::TAXor(TABool& operand_1, TABool& operand_2): TA("^"), TAOperationBinary(operand_1,operand_2,"^") {

}

string TAXor::generateRepresentation() {
	return TAOperationBinary::generateRepresentation();
}

void TAXor::evaluate() { 

}

void TAXor::printState() {

}