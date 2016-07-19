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
#include <fstream>
#include "Author.h"
using namespace std;

class Book
{
public:
	Book();
	Book(Author autho, string titl, int numPage, double pric);
	~Book();
	string GetTitle() const;
	int GetNumPages() const;
	double GetPrice() const;
	string GetAuthorName() const;
	string GetAuthorAddress() const;
	void writeData(ofstream&);
	void readData(ifstream&);
	Author GetAuthor() const;
private:
	Author author;
	string title;
	int numPages;
	double price;
};

