#include "Statement/TAIfElseStatement.h"
#include <iostream>

using namespace std;

TAIfElseStatement :: TAIfElseStatement (TATerm& condition, TAStatement& ifStatement, TAStatement& elseStatement)
: condition(condition), ifStatement(ifStatement), elseStatement(elseStatement){
}

void TAIfElseStatement :: evaluate (){
	
	condition.evaluate();

	if (condition.getValue().getBool()) {
		ifStatement.evaluate();
	} else {
		elseStatement.evaluate();
	}
}

void TAIfElseStatement :: list (){
	cout << "if ( ";
	condition.list();
	cout << " ) { " << endl;
	ifStatement.list();
	cout << endl << " } " << endl << " else { " << endl;
	elseStatement.list();
	cout << endl << " } " << endl;
}
