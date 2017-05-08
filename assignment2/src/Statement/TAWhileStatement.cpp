#define NDEBUG
#include <assert.h>

#include "Statement/TAWhileStatement.h"
#include <iostream>

using namespace std;

TAWhileStatement :: TAWhileStatement (TATerm * condition, TAStatement * body){

       assert (condition != NULL);
       assert (body != NULL);
 
      this -> condition = condition;
      this -> body = body;
}

void TAWhileStatement :: evaluate(){

	while (true){

		condition -> evaluate();

		if (!condition -> getValue().getBool()){
			break;
		}		
		
		body -> evaluate();
	}
}

void TAWhileStatement :: list(ostream & os){
	
	os << "while ( ";
	condition -> list(os);
	os << " ){" << endl;
	body -> list(os);
	os << endl << "}" <<endl;
}
