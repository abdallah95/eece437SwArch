#include "tasub.h"


TASub::TASub(TAInt& operand_1, TAInt& operand_2): TAOperationBinary(operand_1,operand_2,"-") {

}

TASub::TASub(TADouble& operand_1, TADouble& operand_2): TAOperationBinary(operand_1,operand_2,"-") {

}

void TASub::evaluate() { 

}

void TASub::printState() {

}