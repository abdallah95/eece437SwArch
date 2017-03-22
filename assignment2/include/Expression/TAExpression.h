#ifndef TAEXPRESSION_H
#define TAEXPRESSION_H

#include "base/Evaluable.h"
#include "base/Listable.h"
#include "TAVar.h"

//Represents an expression that can be evaluated to a primitve value (Boolean or Number).

class TAExpression : public Evaluable, public Listable {
public:
	virtual void setInput(TAVar*) = 0;
	virtual TAVar* getState() = 0;
};

#endif
