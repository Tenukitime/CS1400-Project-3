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
#include "Book.h"
#include "Author.h"
#include "Exception.h"
#include <string>
#include <iostream>


using namespace std;


// The Book Constructor Method
// Purpose: default constructor
// Parameters: none
// Returns: none
Book::Book() 
{
}

// The Book Constructor Method
// Purpose: parameterized constructor
// Parameters: Autor autho, string titl, int numPage, double pric
// Returns: none
Book::Book(Author autho, string titl, int numPage, double pric) 
: author(autho), title(titl), numPages(numPage), price(pric)
{

}

// The Book Deconstructor Method
// Purpose: Book Deconstructor
// Parameters: none
// Returns: none
Book::~Book()
{
}

// The GetTitle Method
// Purpose: return title
// Parameters: none
// Returns: string title
string Book::GetTitle() const {
	return title;
}

// The GetNumPages Method
// Purpose: Return numPages
// Parameters: none
// Returns int numPages
int Book::GetNumPages() const {
	return numPages;
}

// The GetPrice Method
// Purpose: return price
// Parameters: none
// Returns: double price
double Book::GetPrice() const {
	return price;
}

// The GetAuthorName Method
// Purpose: get and return authors name
// Parameters: none
// Returns string author.GetName()
string Book::GetAuthorName() const {
	return author.GetName();
}

// The GetAuthorAddress Method
// Purpose: get and return authors address
// Parameters: none
// Returns string author.GetAddress()
string Book::GetAuthorAddress() const {
	return author.GetAddress();
}

// The GetAuthor Method
// Purpose: returns author object
// Parameters: none
// Returns Author object
Author Book::GetAuthor() const {
	return author;
}

// The writeData Method
// Purpose: write data to file
// Parameters:
// Returns: none
void Book::writeData(ofstream& stream) {
	author.writeData(stream);
	stream << title << endl;
	stream << numPages << endl;
	stream << price << endl;
}

// The readData Method
// Purpose: read data from file
// Parameters:
// Returns:
void Book::readData(ifstream& reader) {
	author.readData(reader);

	string line;

	getline(reader, line);

	if (reader.fail()) {
		if (reader.eof()) {
			throw new Exception(0);
		}
		else {
			throw new Exception(1);
		}
	}
	title = line;

	getline(reader, line);

	if (reader.fail()) {
		if (reader.eof()) {
			throw new Exception(0);
		}
		else {
			throw new Exception(1);
		}
	}
	
	try {
		numPages = stoi(line);
	}
	catch (invalid_argument) {
		throw new Exception(1);
	}

	getline(reader, line);

	if (reader.fail()) {
		if (reader.eof()) {
			throw new Exception(0);
		}
		else {
			throw new Exception(1);
		}
	}
	try {
		price = stod(line);
	}
	catch (invalid_argument) {
		throw new Exception(1);
	}
}