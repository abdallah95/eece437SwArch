#define NDEBUG
#include <assert.h>
#include <stdlib.h>

#include "System/TASystem.h"
#include <sstream>

unsigned int TASystem :: nextId = 0;

TASystem :: TASystem (string name){
 
   systemDeadlock = false;

   systemId = nextId ++;
 
   if (name == ""){
        stringstream ss;
        ss << "system" << systemId; 
        systemName = ss.str();
   } else {
        systemName = name;
   }
}

void TASystem :: list(ostream & os){

      //TODO Fill this
}

bool TASystem :: addComponent (TAComponent * newComponent){

   assert (newComponent != NULL);

   for (unsigned int k = 0; k < components.size(); k++){
         if (components[k] -> getId() == newComponent -> getId()){
             return false;
         }
   }   

   components.push_back(newComponent);
   return true;
}

bool TASystem :: addInteraction (TAInteraction * newInteraction){

   assert (newInteraction != NULL);

   for (unsigned int i = 0; i < interactions.size(); i++){
            if (interactions[i] -> getId() == newInteraction -> getId()){
                      return false;
            }
   }

   vector <TAPort *> ports = newInteraction -> getPorts();

   for (unsigned int k = 0; k < ports.size(); k ++){

         assert(ports[k] != NULL && ports[k] -> getComponent() != NULL);
         addComponent (ports[k] -> getComponent());                      
       
   }

   interactions.push_back(newInteraction);

}

void TASystem :: evaluate(){

 if (systemDeadlock){
   return;
 }

 //Clear list
 readyInteractions.clear();

 //Fill readyInteractions 
 for (unsigned int i = 0; i < interactions.size(); i++){

       TAInteraction * interaction = interactions[i];

       assert (interaction != NULL);

       if (interaction -> isReady()){
          readyInteractions.push_back(interaction);
       } 
 }

 selectedInteractions.clear();
 
 while (!readyInteractions.empty()){

      if (readyInteractions.size() == 1){

          selectedInteractions.push_back(readyInteractions[0]);
          readyInteractions.clear();
          break;

      } else { //Select one of them non-determinstically

         time_t t;
         srand( (unsigned) time(&t));

         unsigned int selected = rand() % readyInteractions.size();

         TAInteraction * interaction = readyInteractions[selected];
         selectedInteractions.push_back(interaction);
         
         vector <TAInteraction *> remainingInteractions;

         for (unsigned int k = 0; k < readyInteractions.size(); k++){
            if (readyInteractions[k] -> getId() != interaction -> getId() 
             && !inConflict(interaction, readyInteractions[k])){
                 remainingInteractions.push_back(readyInteractions[k]);                   
            }
         }

         readyInteractions.clear();
         readyInteractions.swap(remainingInteractions);
      }
 }

 if (selectedInteractions.empty()){

   systemDeadlock = true;

 } else {

   for (int k = 0; k < selectedInteractions.size(); k++){
           concurrExecute (selectedInteractions);
   }
 }

} 

void TASystem :: concurrExecute (vector <TAInteraction *> interactions){

}

bool TASystem :: inConflict (TAInteraction * int1, TAInteraction * int2){

   vector <TAComponent *> components1 = int1 -> getComponents();
   vector <TAComponent *> components2 = int2 -> getComponents();

   for (unsigned int i = 0; i < components1.size(); i++){

       for (unsigned int j = 0; j < components2.size(); j++){
            if (components1[i] -> getId() == components2[j] -> getId()){
                    return true; //Found conflict
            }
       }
   }

   return false;   
}
