#include "taequal.h"


TAEqual::TAEqual(TAInt& operand_1, TAInt& operand_2): TAOperationBinary(operand_1,operand_2,"=") {

}

TAEqual::TAEqual(TADouble& operand_1, TADouble& operand_2): TAOperationBinary(operand_1,operand_2,"=") {

}

void TAEqual::evaluate() { 

}

void TAEqual::printState() {

}