#define NDEBUG
#include <assert.h>

#include "Statement/TAIfElseStatement.h"
#include <iostream>

using namespace std;

TAIfElseStatement :: TAIfElseStatement (TATerm * condition, TAStatement * ifStatement, TAStatement * elseStatement)
{
        assert (condition != NULL);
        assert (ifStatement != NULL); 
        assert (elseStatement != NULL);
 
        this -> condition = condition;
        this -> ifStatement = ifStatement;
        this -> elseStatement = elseStatement;

}

void TAIfElseStatement :: evaluate (){
	
	condition -> evaluate();

	if (condition -> getValue().getBool()) {
		ifStatement -> evaluate();
	} else {
		elseStatement -> evaluate();
	}
}

void TAIfElseStatement :: list (ostream & os){
	os << "if ( ";
	condition -> list(os);
	os << " ) { " << endl;
	ifStatement -> list(os);
	os << endl << " } " << endl << " else { " << endl;
	elseStatement -> list(os);
	os << endl << " } " << endl;
}
