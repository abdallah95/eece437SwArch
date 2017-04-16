
#pragma once 
#include <Expression/TATerm.h>
#include <string>
#include <iostream>
using namespace std; 

struct TANamedObj : public TATerm {
  string name; 

  TANamedObj() {}

  TANamedObj(const string & s) : name(s) {
  }

  virtual void set(const TAValue& value) = 0;

  virtual void list(ostream & os = cout) const {
    os << name;
  }
};

typedef TANamedObj TAVariable;
