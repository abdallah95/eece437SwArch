#include <iostream>

#include "Component/TAComponent.h"
#include "Interaction/TAInteraction.h"
#include "System/TASystem.h"

using namespace std;

int main(int argc, char ** argv){

 TASystem * mainSystem  = new TASystem("mainSystem");
 TAComponent * comp1 = new TAComponent();
 TAComponent * comp2 = new TAComponent();
 
 TAState * s0 = comp1 -> addState("s0");
 TAState * s1 = comp1 -> addState("s1");

 TAState * t0 = comp2 -> addState("t0");
 TAState * t1 = comp2 -> addState("t1");

 return 0;
}
