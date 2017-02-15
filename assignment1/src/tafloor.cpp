#include "tafloor.h"


TAFloor::TAFloor(TADouble& operand): TA("floor"), TAOperationUnary(operand,"floor") {

} 

string TAFloor::generateRepresentation() {
	return TAOperationUnary::generateRepresentation();
}

void TAFloor::evaluate() { 

}

void TAFloor::printState() {

}