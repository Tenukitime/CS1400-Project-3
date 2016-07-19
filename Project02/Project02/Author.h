// File Prologue
// Name: Kyle Gray
// Project: Project02
// Date: 07/09/2016

// I declare that the following source code was written by me, or provided
// by the instructor for this project.  I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in vaolation of 
// this policy.



#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Exception.h"

using namespace std;

class Author
{
public:
	Author();
	Author(string n, string a);
	string GetName() const;
	string GetAddress() const;
	~Author();
	void readData(ifstream&);
	void writeData(ofstream&);
private:
	string name;
	string address;
};

