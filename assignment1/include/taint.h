#ifndef TAINT_H
#define TAINT_H

#include "tadata.h"

class TAInt: public TAData {
	int val;
public:
	TAInt(string name = "");
	void set(int);
	int getVal();
};


#endif