#include "TAWhileStatement.h"
#include <iostream>

using namespace std;

void TAWhileStatement :: evaluate(){

	while (true){

		condition -> evaluate();

		if (!condition -> getState()){
			break;
		}		
		
		body -> evaluate();
	}
}

void TAWhileStatement :: list(){
	
	cout << "while ( ";
	condition -> list();
	cout << " ){" << endl;
	body -> list;
	cout << endl << "}" <<endl;
}
