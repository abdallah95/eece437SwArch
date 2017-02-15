#include "tadata.h"

TAData::TAData(string name): TA(name){
}

string TAData::generateRepresentation() {
	return name;
}