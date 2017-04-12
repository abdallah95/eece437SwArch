#include <iostream>
#include "Statement/TAAssignStatement.h"

using namespace std;

TAAssignStatement :: TAAssignStatement (TANamedObj& target, TATerm& exp)
: target(target), exp(exp){
}

void TAAssignStatement :: evaluate(){

	exp.evaluate();

//TODO Remove comment after implementing getState()

	target.set(exp.getValue());	
}

void TAAssignStatement :: list(){
	target.list();
	cout << " = " ;
	exp.list();
	cout << " ; ";
}
