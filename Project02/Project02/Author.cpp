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
#include "Author.h"
#include <iostream>

using namespace std;


// The Author Constructor Method
// Purpose: Default Constructor
// Parameters: none
// Returns: none
Author::Author()
{
}

// The Author Constructor Method
// Purpose: Parameterized constructor
// Parameters: string n, string a
// Returns: none
Author::Author(string n, string a) {
	name = n;
	address = a;
}

// The Author Deconstructor Method
// Purpose: Author Deconstructor
// Parameters: none
// Returns: none
Author::~Author()
{
}

// The GetName Method
// Purpose: return name
// Parameters: none
// Returns: string name
string Author::GetName() const {
	return name;
}

// The GetAddress Method
// Purpose: return address
// Parameters: none
// Returns: string address
string Author::GetAddress() const {
	return address;
}

// The readData Method
// Purpose: read data from file
// Parameters: ifstream object
// Returns: none
void Author::readData(ifstream& reader) {
	getline(reader, name);
	if (reader.eof()) {
		throw new Exception(0);
	}
	getline(reader, address);
}

// The writeData Method
// Purpose: write data to file
// Parameters: ofstream object
// Returns: none
void Author::writeData(ofstream& writer) {
	writer << name << endl;
	writer << address << endl;

}