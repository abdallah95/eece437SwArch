#ifndef TADATA_H
#define TADATA_H

#include "ta.h"
#include "lister.h"

class TAData: public TA, public Lister {

public:
	TAData(string name);
	virtual string generateRepresentation();
};

#endif