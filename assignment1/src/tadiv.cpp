#include "tadiv.h"




TADiv::TADiv(TAInt& operand_1, TAInt& operand_2): TAOperationBinary(operand_1,operand_2,"/") {

}

TADiv::TADiv(TADouble& operand_1, TADouble& operand_2): TAOperationBinary(operand_1,operand_2,"/") {

}
