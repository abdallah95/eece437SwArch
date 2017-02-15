#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type {
	std::string signature;
public:
	Type(std::string signature = ""): signature(signature) {}
	bool isOfType(Type&);
	std::string getSignature();
};

#endif