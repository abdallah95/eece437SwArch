#define NDEBUG
#include <assert.h>

#include "Statement/TASeqListOfStatements.h"
#include <iostream>

using namespace std;

TASeqListOfStatements :: TASeqListOfStatements (TAAtomicStatement * s, TAStatement * list )
{ 
   assert (s != NULL);
   assert (list != NULL);
 
   this -> s1 = s;
   this -> l = list;

}

void TASeqListOfStatements :: evaluate(){

	s1 -> evaluate();

	l -> evaluate();

}

void TASeqListOfStatements :: list(ostream & os){

	s1 -> list(os);
	os << endl;
	l -> list(os);
	os << endl;
}
