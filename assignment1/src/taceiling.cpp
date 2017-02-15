#include "taceiling.h"


TACeiling::TACeiling(TADouble& operand): TA("ceiling"), TAOperationUnary(operand,"ceiling") {

} 

string TACeiling::generateRepresentation() {
	return TAOperationUnary::generateRepresentation();
}

void TACeiling::evaluate() { 

}

void TACeiling::printState() {

}