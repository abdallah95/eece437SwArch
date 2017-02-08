#ifndef TADATA_H
#define TADATA_H

#include "ta.h"

class TAData: public TA {
protected:
	virtual string generateRepresentation();
public:
	TAData(string name = "");
	virtual void list();
};

#endif