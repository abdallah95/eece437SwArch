#include "taint.h"


TAInt::TAInt(string name): TAData(name){
	
}

void TAInt::set(int val) {
	this->val = val;
}