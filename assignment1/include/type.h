#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>

class Type {
	std::string signature;
	std::vector<Type> superClassTypes;
	std::vector<Type> dynamicContentTypes;
public:
	Type(std::string className = "");
	std::string getSignature();
	bool isOfType(Type& type);
};

#endif