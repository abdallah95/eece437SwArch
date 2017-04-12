#include "Expression/TAConditionalOpTerm.h"

TAValue& TAConditionalOpTerm::evaluateExecute(TATerm& formula1, TATerm& term2, TATerm& term3) {
	formula1.evaluate();
	bool f1val = formula1.getValue().getBool();
	if(f1val) {
		term2.evaluate();
		val.set(term2.getValue());
	} else {
		term3.evaluate();
		val.set(term3.getValue());
	}
}