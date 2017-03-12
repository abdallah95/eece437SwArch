#include "TAEmptyStatement.h"

static TAEmptyStatement * TAEmptyStatement :: getInstance(){

	if (instance == NULL){
		instance = new TAEmptyStatement();
	}

	return instance;
}
