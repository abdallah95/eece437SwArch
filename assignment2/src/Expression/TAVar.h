#include "TAFormula.h"
#include "TATerm.h"
#include "Settable.h"

//Represents a value holder that can be changed and set directly

class TAVar : public Settable {

};

//Represents a boolean value holder
class TABoolVar : public TAVar, public TAFormula {

};

//Represents a number value holder
class TANumVar : public TAVar, public TATerm {

};

//Represents an array access variable; allows retrieval of the corresponding array member value and directly setting it
class TAArrayAccess : public TAVar {

};
