#ifndef EVALUABLE_H
#define EVALUABLE_H

//@Functional Interface 

class Evaluable {

	public:

/** 
Evaluates the evaluable object and stores its value internally (should be retrievable by another methods).
*/
	virtual void evaluate() = 0;				
};

#endif
