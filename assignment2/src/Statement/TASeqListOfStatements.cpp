#include "Statement/TASeqListOfStatements.h"
#include <iostream>

using namespace std;

TASeqListOfStatements :: TASeqListOfStatements (TAAtomicStatement& s, TAStatement& list )
:s1(s), l(list){
}

void TASeqListOfStatements :: evaluate(){

	s1.evaluate();

	l.evaluate();

}

void TASeqListOfStatements :: list(){

	s1.list();
	cout << endl;
	l.list();
	cout << endl;
}
