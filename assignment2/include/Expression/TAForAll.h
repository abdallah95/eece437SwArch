#ifndef TAFORALL_H
#define TAFORALL_H

#include "TATerm.h"
#include "TADomain.h"
#include "TABool.h"
#include <Expression/TABoolBinaryOp.h>

// there exists formula
class TAForAll : public TABoolBinaryOp {

public:
	TAForAll(TATerm& term, TADomain& domain)
	: TABoolBinaryOp(term,domain){}
	virtual TAValue& evaluateExecute(TATerm& term, TADomain& domain);
};

#endif
