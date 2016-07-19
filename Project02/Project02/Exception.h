#pragma once

#include <string>
using namespace std;
class Exception
{
private:
	int errorCode;
public:
	Exception();
	Exception(int errorCode);
	~Exception();
	string check();
};

