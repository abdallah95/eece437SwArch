#ifndef TADOUBLE_H
#define TADOUBLE_H

#include "tadata.h"

class TADouble: public TAData {
	double val;
public:
	TADouble(string name = "");
	void set(double);
};


#endif