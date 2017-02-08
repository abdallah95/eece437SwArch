#ifndef TA_H
#define TA_H

#include "type.h"
#include <string>

using namespace std;

class TA: public Type {
protected:
	string name;
public:
	TA(string name = "");
//	virtual Type& type() = 0;
	virtual void list() = 0;
//	virtual bool isInstanceOf(Type&) = 0;
	virtual string generateRepresentation() = 0;
};

#endif