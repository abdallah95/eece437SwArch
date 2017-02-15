#include "tanot.h"


TANot::TANot(TABool& operand): TA("!"), TAOperationUnary(operand,"!") {

} 

string TANot::generateRepresentation() {
	return TAOperationUnary::generateRepresentation();
}

void TANot::evaluate() { 

}

void TANot::printState() {

}