#include "tadata.h"
#include <iostream>

TAData::TAData(string name): TA(name){}

void TAData::list() {
	cout << generateRepresentation() << endl;
}

string TAData::generateRepresentation() {
	return name;
}