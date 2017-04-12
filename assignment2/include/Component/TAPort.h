#pragma once

#include "TAComponent.h"

class TAComponent;
//TAValues ..
//TODO Add methods (and fields) that determine all variables associated with this port

class TAPort {
	
	private:
		static unsigned int nextId;

		unsigned int portId;
		string portName; //Optional
		TAComponent * parentComponent;
		//vector <TAInteraction *> interactions;

	public:

	TAPort(TAComponent * component, string name = "");
	
	string getName(){
		return portName;
	}

	unsigned int getId(){
		return portId;
	}

	TAComponent * getComponent(){
		return parentComponent;
	}
};
