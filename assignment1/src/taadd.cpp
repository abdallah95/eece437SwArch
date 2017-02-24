#include "taadd.h"

TAAdd::TAAdd(TAInt& operand_1, TAInt& operand_2): TAOperationBinary(operand_1,operand_2,"+") {

}

TAAdd::TAAdd(TADouble& operand_1, TADouble& operand_2): TAOperationBinary(operand_1,operand_2,"+") {

}

void TAAdd::evaluate() {

}

void TAAdd::printState() {

}