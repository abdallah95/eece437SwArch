#ifndef LISTER_H
#define LISTER_H

#include <string>

class Lister {
public:
	virtual void list();
	virtual std::string generateRepresentation();
};

#endif