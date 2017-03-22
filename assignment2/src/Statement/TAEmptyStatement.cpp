#include "Statement/TAEmptyStatement.h"

TAEmptyStatement * TAEmptyStatement :: getInstance(){

	if (instance == NULL){
		instance = new TAEmptyStatement();
	}

	return instance;
}
