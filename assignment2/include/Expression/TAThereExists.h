#ifndef TATHEREEXISTS_H
#define TATHEREEXISTS_H

#include "TATerm.h"
#include "TADomain.h"
#include "TABool.h"
#include <Expression/TANamedObj.h>
#include <Expression/TABoolBinaryOp.h>

// there exists formula
class TAThereExists : public TATerm {
	TATerm& term;
	TADomain& domain;
	TAVariable& x;
public:
	TAThereExists(TATerm& term, TADomain& domain, TAVariable& x)
	: term(term), domain(domain), x(x){}
	virtual TAValue& evaluate(){
		return evaluateExecute(term,domain,x);
	}
	virtual TAValue& evaluateExecute(TATerm& term, TADomain& domain, TAVariable& x);
};

#endif
