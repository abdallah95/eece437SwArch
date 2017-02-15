#include "taminus.h"


TAMinus::TAMinus(TAInt& operand): TA("-"), TAOperationUnary(operand,"-") {

}

TAMinus::TAMinus(TADouble& operand): TA("-"), TAOperationUnary(operand,"-") {

}

string TAMinus::generateRepresentation() {
	return TAOperationUnary::generateRepresentation();
}

void TAMinus::evaluate() { 

}

void TAMinus::printState() {

}