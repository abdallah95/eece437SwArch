#include "taoperationbinary.h"

TAOperationBinary::TAOperationBinary(TAData& operand_1, TAData& operand_2, string opName)
: TAOperation(opName),operand_1(operand_1), operand_2(operand_2) {
	
}


string TAOperationBinary::generateRepresentation() {
	return "(" + opName + " " + operand_1.generateRepresentation()
	 + " " + operand_2.generateRepresentation() + " " + ")";
}
