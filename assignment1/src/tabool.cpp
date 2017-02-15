#include "tabool.h"

TABool::TABool(string name): TA(name), TAData(name){
	
}

void TABool::set(bool val){
	this->val = val;
}

bool TABool::getVal() {
	return val;
}