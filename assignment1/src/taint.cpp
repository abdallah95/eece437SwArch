#include "taint.h"

TAInt::TAInt(string name): TA(name), TAData(name){
	this->type = Type(__FUNCTION__);
}

void TAInt::set(int val) {
	this->val = val;
}

int TAInt::getVal() {
	return val;
}