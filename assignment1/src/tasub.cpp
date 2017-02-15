#include "tasub.h"


TASub::TASub(TAInt& operand_1, TAInt& operand_2): TA("-"), TAOperationBinary(operand_1,operand_2,"-") {

}

TASub::TASub(TADouble& operand_1, TADouble& operand_2): TA("-"), TAOperationBinary(operand_1,operand_2,"-") {

}

string TASub::generateRepresentation() {
	return TAOperationBinary::generateRepresentation();
}

void TASub::evaluate() { 

}

void TASub::printState() {

}