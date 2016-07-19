#include "Exception.h"



Exception::Exception()
{
}


Exception::Exception(int _errorCode)
{
	errorCode = _errorCode;
}


Exception::~Exception()
{
}


string Exception::check() {
	if (errorCode == 0) {
		return "Error: end of file";
	}
	else if (errorCode == 1) {
		return "Error: read error";
	}
	else {
		return "Error: could not open the file";
	}
}