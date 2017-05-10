#pragma once
#include "base/Evaluable.h"
#include "base/Listable.h"

#include "Interaction/TAInteraction.h"
#include "Component/TAComponent.h"

#include <vector>

/*  Represents abstraction of an LTS System   */

class TASystem : public Evaluable, public Listable {

   private:
   static unsigned int nextId;
 
   unsigned int systemId;
   string systemName;

   bool systemDeadlock;

   vector <TAComponent *> components;
   vector <TAInteraction *> interactions;

   vector <TAInteraction *> readyInteractions;
   vector <TAInteraction *> selectedInteractions;

   void concurrExecute(vector <TAInteraction *> interactions);

   bool inConflict (TAInteraction *, TAInteraction *);  

   public:

   //Constructor
   TASystem (string name = "");   

   //Executes an iteration
   void evaluate();

   //List system
   void list(ostream & os);

   bool addComponent(TAComponent * newComponent);

   bool addInteraction(TAInteraction * newInteraction);  

};
