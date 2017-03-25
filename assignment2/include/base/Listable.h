#ifndef LISTABLE_H
#define LISTABLE_H

#include <iostream>

using namespace std;

// @Functional Interface 

class Listable {
	
	public:
/**
   Lists this object i.e. prints its identifying name 
**/
	virtual void list(ostream & os) = 0;
};

#endif
