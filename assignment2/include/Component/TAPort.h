#pragma once

//TODO COnsider implementing list method

#include "TAComponent.h"

class TAComponent;

/* Represents abstraction of a port in an LTS. */

class TAPort {
	
	private:
		static unsigned int nextId; //Used to assure each port is given a 'unique' id

		unsigned int portId; //Unique id assigned to this port
		string portName; //Optional name
		TAComponent * parentComponent; //A port is associated with a single owner component

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
