#include "taoperationbinary.h"

TAOperationBinary::TAOperationBinary(TA& operand_1, TA& operand_2, string name)
: TAOperation(name),operand_1(operand_1), operand_2(operand_2) {
	
}


string TAOperationBinary::generateRepresentation() {
	return "(" + name + " " + operand_1.generateRepresentation()
	 + " " + operand_2.generateRepresentation() + " " + ")";
}
