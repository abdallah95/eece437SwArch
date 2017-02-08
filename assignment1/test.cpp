#include <iostream>
#include "taint.h"
#include "tadouble.h"
#include "taceiling.h"
#include "tabool.h"
#include "talessthan.h"
#include "taand.h"

using namespace std;


int main(){

	TAInt x("x");
	TADouble d("d");
	TACeiling y(d); // denotes y is the ceiling of d
	TABool b("b");
	TALessThan t1 (x,y); // denotes x < y
	TAAnd t2 (b, t1); // denotes b and t1
	t1.list();
	t2.list();// should print: (& b (< x (ceiling d ) ) )
	x.set(5);
	d.set(2.3);
	b.set(true);
	// t1.evaluate();
	// t1.printState();// should print: false
	d.set(5.3);
	// t1.evaluate();
	// t1.printState();// should print: true

	return 0;
}