#include "TAIfElseStatement.h"
#include <iostream>

using namespace std;

TAIfElseStatement :: TAIfElseStatement (TAFormula * condition, TAStatement * ifStatement, TAStatement * elseStatement){

	e = condition;
	s1 = ifStatement;
	s2 = elseStatement;

}

void TAIfElseStatement :: evaluate (){
	
	e -> evaluate();

	if ( e -> getState()){
		s1 -> evaluate();
	}

	else {
		s2 -> evaluate();
	}
}

void TAIfElseStatement :: list (){
	cout << "if ( ";
	e -> list();
	cout << " ) { " << endl;
	s1 -> list();
	cout << endl << " } " << endl << " else { " << endl;
	s2 -> list();
	cout << endl << " } " << endl;
}
