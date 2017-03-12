#include "TASeqOfStatements.h"
#include <iostream>

using namespace std;

TASeqOfStatements :: TASeqOfStatements (TAAtomicStatement * s, TAStatement * list ){
	s1 = s;
	l = list;
}

void TASeqOfStatements :: evaluate(){

	s1 -> evaluate();

	l -> evaluate();

}

void TASeqOfStatements :: list(){

	s1 -> list();
	cout << endl;
	l -> list();
	cout << endl;
}
