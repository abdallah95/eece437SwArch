#include "Component/TAPort.h"

TAPort::TAPort (TAComponent * component, string name){
      portName = name;
      parentComponent = component;
      portId = nextId ++;
}

