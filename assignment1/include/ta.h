#ifndef TA_H
#define TA_H

#include "type.h"
#include <string>
#include <set>

typedef std::string string; 

class TA {
	static std::set<string> variableNames;
protected:
	string name;
	Type type;
public:
	TA(string name = "");
	virtual Type getType();
	virtual void list();
	virtual string generateRepresentation() = 0;
};

#endif