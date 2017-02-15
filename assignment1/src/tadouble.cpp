#include "tadouble.h"

TADouble::TADouble(string name): TA(name), TAData(name) {

}

void TADouble::set(double val) {
	this->val = val;
}

double TADouble::getVal() {
	return val;
}