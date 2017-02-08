#include "tabool.h"




TABool::TABool(string name): TAData(name){
	
}

void TABool::set(bool val){
	this->val = val;
}