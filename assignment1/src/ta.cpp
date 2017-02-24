#include "ta.h"
#include <iostream>
#include "IllegalStateException.h"

using namespace std;

set<string> TA::variableNames;

TA::TA(string name): name(name) {
	if(name!="" && variableNames.find(name)!=variableNames.end()){
		throw IllegalStateException("Cannot define two variables with the same name");
	}
	variableNames.insert(name);
}


Type TA::getType() {
	return type;
}