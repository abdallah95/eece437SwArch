#ifndef CONCURRENT_
#define CONCURRENT_

#include "TAStatement.h"
#include "Expression/TATerm.h"

using namespace std;

/* 

   Represents a list of statements that should be evaluated and executed concurrently.

   For simplicity, we are forcing a concurrent statement to contain only assignment statements.

   Conditional logic can be embedded in ternary expressions of the form (c) ? e1 : e2. 

*/

// TODO Implement some conversion between conditional (and maybe loop ? ) statements to equivalent assignment statements

class TAConcurrentListOfStatements : public TAStatement {

	private:

	TAAtomicStatement * s1;
	TAStatement * l;
	
	public:

	TAConcurrentListOfStatements (TAAtomicStatement * s, TAStatement * list);

	virtual void list(ostream & os);
	
	virtual void evaluate();

        //Intermediate stage in concurrent statement evaluation. Evaluate all expressions but execute no assignment statement.
        void evaluateExpressions();

        //Second stage of concurrent statement evaluation. 
        void executeAssignments();

	virtual bool isList(){
		return true;
	}

	virtual bool isConcurList(){
		return true;
	}
};

#endif
