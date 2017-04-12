#include "Statement/TAEmptyStatement.h"

TAEmptyStatement TAEmptyStatement::instance;

TAEmptyStatement& TAEmptyStatement :: getInstance(){
	return instance;
}
