#include <Expression/TAForAll.h>

TAValue& TAForAll::evaluateExecute(TATerm& term, TADomain& domain) {
	TAValue* next = 0;
	while((next=domain.iterate())!=0) {
		val.set(term.evaluate());
		if(!val.getBool()){
			val.set(false);
			return val;
		}
	}
	val.set(true);
	return val;
}
