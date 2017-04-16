#ifndef TAFORALL_H
#define TAFORALL_H

#include "TATerm.h"
#include "TADomain.h"
#include "TABool.h"
#include <Expression/TANamedObj.h>
#include <Expression/TABoolBinaryOp.h>

// there exists formula
class TAForAll : public TATerm {
	TATerm& term;
	TADomain& domain;
	TAVariable& x;
public:
	//NOTE: it's up to the programmer to make sure that term contains x as a variable 
	TAForAll(TATerm& term, TADomain& domain, TAVariable& x)
	:term(term), domain(domain), x(x){}
	virtual TAValue& evaluate(){
		return evaluateExecute(term,domain,x);
	}
	virtual TAValue& evaluateExecute(TATerm& term, TADomain& domain, TAVariable& x);
};

#endif
