#pragma once

#include <TAComponent.h>
//TAVars ..

class TAPort {
	
	private:
		static unsigned int nextId;

		unsigned int portId;
		String portName; //Optional

		vector <TAComponent *> components;

	public:

	TAPort(String name = ""){
		portName = name;
		portId = nextId ++;
		components.clear(); //Initially empty
	}

	bool addComponent(TAComponent * comp){
		
		if (hasComponent(comp)){
			return false;
		}

		components.insert(comp);
		return true;
	}

	bool hasComponent(TAComponent * comp){
		for (int i = 0; i < components.size(); i++){
			if (components[i]->getId() == comp -> getId()){
				return true;	
			}
		}
		return false;
	}

};
