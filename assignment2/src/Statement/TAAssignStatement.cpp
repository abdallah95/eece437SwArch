#define NDEBUG
#include <assert.h>

#include <iostream>
#include "Statement/TAAssignStatement.h"

using namespace std;

TAAssignStatement :: TAAssignStatement (TANamedObj * target, TATerm * exp)
{
     assert (target != NULL);
     assert (exp != NULL);
     this -> target = target;
     this -> exp = exp;
   
}

void TAAssignStatement :: evaluate(){

	exp -> evaluate();

//TODO Remove comment after implementing getState()

	target -> set(exp -> getValue());	
}

void TAAssignStatement :: list(ostream & os){
	target -> list(os);
	os << " = " ;
	exp -> list(os);
	os << " ; ";
}
