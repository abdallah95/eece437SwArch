#include <iostream>
#include "Component/TAComponent.h"

using namespace std;

int main(int argc, char ** argv){

  TAComponent component ("Test Component");
  component.addState("S0");
  component.addState("S1");
  return 0;
}
