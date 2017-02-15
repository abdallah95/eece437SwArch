#include "taimplies.h"

TAImplies::TAImplies(TABool& operand_1, TABool& operand_2): TA("=>"), TAOperationBinary(operand_1,operand_2,"=>") {

}

string TAImplies::generateRepresentation() {
	return TAOperationBinary::generateRepresentation();
}

void TAImplies::evaluate() { 

}

void TAImplies::printState() {

}