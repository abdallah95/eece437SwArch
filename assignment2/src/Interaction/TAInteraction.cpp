#include "Interaction/TAInteraction.h"
#include <sstream>

unsigned int TAInteraction :: nextId = 0;

//Constructor
TAInteraction :: TAInteraction (string name, TAStatement * s, TATerm * g){

        interactionId = nextId ++;
         
        if (name == ""){
           stringstream ss;
           ss << "interaction_" << interactionId;
           interactionName = ss.str();  
        } else {
           interactionName = name;
        }

        statement = s;
        guard = g;
}

bool TAInteraction :: addPort (TAPort * port){

        assert (port != NULL && port -> getComponent() != NULL);
                        
        TAComponent * component = port -> getComponent();
                         
        //An interaction has at most one port per component
        if (comp2Port[component] != NULL){
               return false;
        }

        comp2Port[component] = port;
        components.push_back(component);
        ports.push_back(port);

        return true;
}

void TAInteraction :: addStatement(TAAtomicStatement * newStatement){

     assert (newStatement == NULL);

     assert (newStatement -> isConcurList() || newStatement -> isAssign());
 
     if (statement == NULL){

         statement = newStatement;

     } else {

        assert (statement -> isAssign());

        statement = new TAConcurrentListOfStatements(newStatement, statement);
     }
}

void TAInteraction :: addGuard (TATerm * newCondition){

     assert(newCondition == NULL);
                     
     if (guard == NULL){
     
         guard = newCondition;

     } else {

         //guard = new TALAnd(guard, newCondition);
     }
}

void TAInteraction :: list(ostream & os){
   os << "Interaction " << interactionName << " { " << endl;
 
   os << "Ports: ";
   for (unsigned int i = 0; i < ports.size(); i++){
       os << ports[i] -> getName() << ", ";
   }
   os << endl;

   os << "Guard: ";
   guard -> list(os);

   os << endl << "Action: ";
   //statement -> list(os);

}

//Determines if this interaction is ready to run or not
bool TAInteraction :: isReady(){


    guard -> evaluate();
  
    if (!(guard -> getValue()).getBool()){ //Guard evaluated to false
          return false;
    }

    for (unsigned int i = 0; i < components.size(); i++){

         TAComponent * component = components[i];
         assert (component != NULL);

         TAState * currState = component -> getState();
         assert (currState != NULL);

         TAPort * port = comp2Port[component];
         assert (port != NULL);
        
         currState -> evaluate(); //Determine which ports are ready now

         if (!currState -> isPortReady(port)){
              return false;
         }
    }

   //Now all ports of interaction are ready
   return true; //Interaction is ready to run
}

//Evaluate aka execute interaction
void TAInteraction :: evaluate(){

  for (unsigned int i = 0; i < components.size(); i++){

         TAComponent * component = components[i];
         assert (component != NULL);

         TAPort * port = comp2Port[component];
         assert (port != NULL);

         component -> execute(port);  
  }
}
