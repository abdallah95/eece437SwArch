#ifndef IllegalStateException_H
#define IllegalStateException_H

#include <exception>
#include <string>

class IllegalStateException: public std::exception {
	std::string message;
public:
	IllegalStateException(std::string message): message(message){}
	~IllegalStateException() throw() {}
	const char * what () const throw () {
      return message.c_str();
   }
};

#endif