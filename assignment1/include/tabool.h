#ifndef TABOOL_H
#define TABOOL_H

#include "tadata.h"

class TABool: public TAData {
	bool val;
public:
	TABool(string name = "");
	void set(bool);
};


#endif