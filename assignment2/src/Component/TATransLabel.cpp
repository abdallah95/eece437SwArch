#include <TATransLabel.h>

TATransLabel::TATransLabel (TAComponent * pComp, TAPort * p, TAFormula * g, TAStatement * s){
 
   if (pComp == NULL || p == NULL || g == NULL || s == NULL){

	throw -1;       //TODO Need to define and handle exceptions more gracefully
    }

#if 0

    if ( !pComp.hasPort(p)){
        throw -2;       //TODO Same as above
    }

#endif
    
    //TODO Check if the statement type is allowed (i.e. concurrent, not loop ...)

    parentComponent = pComp;
    port = p;
    guard = g;
    statement = s;

}

