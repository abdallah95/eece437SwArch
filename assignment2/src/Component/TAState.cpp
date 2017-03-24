#include <TAState.h>

bool TAState::addNextState(TAState * newState){

    for (int i = 0; i < nextStates.size(); i++){
        if (nextStates[i] -> getId() == newState -> getId()){
           return false;
        }
    }

    nextStates.insert(newState);
    return true;
}
