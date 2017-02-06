#include <iostream>
#include "taint.h"
#include "tadouble.h"
#include "taceiling.h"
#include "tabool.h"
#include "talessthan.h"
#include "taand.h"

using namespace std;


int main(){

	TAInt x;
	TADouble d;
	TACeiling y(d); // denotes y is the ceiling of d
	TABool b;
	TALessThan t1 (x,y); // denotes x < y
	TAAnd t2 (b, t1); // denotes b and t1
	TALessThan t3 (x,d); // x and d are not of the same type and

	return 0;
}