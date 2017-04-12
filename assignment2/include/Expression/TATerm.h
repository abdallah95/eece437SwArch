#pragma once 

#include <Expression/TAObj.h>
#include <Expression/TAValue.h>
#include <iostream>
using namespace std;

class TAValue;

struct TATerm : public TAObj {
  TAValue val;


  virtual void printState() const {
    printState(cout);
  }

  virtual const TAValue & getValue() const {
    return val;
  }

  virtual void list(ostream & os = cout) const = 0;
  virtual TAValue & evaluate() =0;
  virtual void printState(ostream & os) const {
    val.print(os);
  }
}; 

