#ifndef TATHEREEXISTS_H
#define TATHEREEXISTS_H

#include "TATerm.h"
#include "TADomain.h"
#include "TABool.h"
#include <Expression/TABoolBinaryOp.h>

// there exists formula
class TAThereExists : public TABoolBinaryOp {

public:
	TAThereExists(TATerm& term, TADomain& domain)
	: TABoolBinaryOp(term,domain){}
	virtual TAValue& evaluateExecute(TATerm& term, TADomain& domain);
};

#endif
