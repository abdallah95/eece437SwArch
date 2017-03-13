#include "Expression/TAVar.h"


TABoolVar::TABoolVar(bool val): val(val){}
	
bool TABoolVar::getVal() {
	return val;
}

void TABoolVar::setVal(bool val) {
	this->val = val;
}