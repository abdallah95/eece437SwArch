#ifndef TATerm_H
#define TATerm_H

#include "base/Evaluable.h"
#include "base/Listable.h"
#include "TAValue.h"

//Represents an expression that can be evaluated to a primitve value (Boolean or Number).

class TATerm : public Evaluable, public Listable {
public:
	virtual void setInput(TAValue*) = 0;
	virtual TAValue* getState() = 0;
};

#endif
