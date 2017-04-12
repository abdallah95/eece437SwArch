#include <Expression/TAThereExists.h>

TAValue& TAThereExists::evaluateExecute(TATerm& term, TADomain& domain) {
	TAValue* next = 0;
	while((next=domain.iterate())!=0) {
		val.set(term.evaluate());
		if(val.getBool()){
			return val;
		}
	}
	val.set(false);
	return val;
}
