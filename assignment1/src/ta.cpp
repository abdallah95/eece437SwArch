#include "ta.h"
#include <iostream>
#include "IllegalStateException.h"

using namespace std;

set<string> TA::variableNames;

TA::TA(string name): name(name), type("TA") {
	if(name!="" && variableNames.find(name)!=variableNames.end()){
		throw new IllegalStateException("Cannot define two variables with the same name");
	}
}

void TA::list() {
	cout << generateRepresentation() << endl;
}

Type TA::getType() {
	return type;
}