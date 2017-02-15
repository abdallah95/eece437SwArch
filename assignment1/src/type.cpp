#include "type.h"

using namespace std;

bool Type::isOfType(Type& t) {
	return this->signature == t.signature;
}

string Type::getSignature() {
	return signature;
}