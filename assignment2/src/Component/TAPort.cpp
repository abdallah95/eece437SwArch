#define NDEBUG
#include <assert.h>
#include <sstream>
#include <stdlib.h>
#include "Component/TAPort.h"

using namespace std;

unsigned int TAPort::nextId = 0;

TAPort::TAPort (TAComponent * component, string name){

      assert (component != NULL);

      parentComponent = component;
      portId = nextId ++;

      if (name == ""){
        
          stringstream ss;
          ss << "port" << portId;
          portName = ss.str();

      } else {
         portName = name;
      }
}

