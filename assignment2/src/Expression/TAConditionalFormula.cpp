#include "Expression/TAConditionalFormula.h"


TAValue& TAConditionalFormula::evaluateExecute(TATerm& formula1, TATerm& formula2, TATerm& formula3) {
	formula1.evaluate();
	bool f1val = formula1.getValue().getBool();
	if(f1val) {
		formula2.evaluate();
		val.set(formula2.getValue().getBool());
	} else {
		formula3.evaluate();
		val.set(formula3.getValue().getBool());
	}
}

