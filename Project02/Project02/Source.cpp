// File Prologue
// Name: Kyle Gray
// Project: Project02
// Date: 07/09/2016

// I declare that the following source code was written by me, or provided
// by the instructor for this project.  I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in vaolation of 
// this policy.


// CS 1410 Programming Project #3
// Copyright 2014, Utah Valley University
//Author: Roger deBry
// Date last modified: October 2015
// Implementation file for main
// =======================================
#include "Header.h"

int main()
{
	// Display Menu 
	int option = 0;
	const int CREATE = 1;
	const int READ = 2;

	cout << "\nCS 1410 Project 3";
	cout << "\nSelect one of the following two options: ";
	cout << "\n   1 - create a test file";
	cout << "\n   2 - read the test file and display the results";
	cout << "\n>> ";

	// run the selected option
	cin >> option;
	if (option == CREATE)
	{
		createTestFile();
		cout << "\nTest file has been created.";
	}
	else if (option == READ)
	{
		readTestFile();
		
	}
	else
	{
		cout << "\nInvalid option.";
	}

	system("PAUSE");
	return 0;
}

void displayBooks(const vector<Book>& books)
{
	// set up cout to display currency
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// display heading
	cout << "\nRecommended Reading List\n";


	// display each account
	for (unsigned i = 0; i < books.size(); i++)
	{
		Author p = books[i].GetAuthor();
		cout << books[i].GetTitle() << '\n';
		cout << p.GetName() << '\n';
		cout << p.GetAddress() << '\n';
		cout << books[i].GetNumPages() << " pages\n";
		cout << '$' << books[i].GetPrice() << "\n\n\n";
	}
}

// This code is provided for you. It creates the test file.
void createTestFile()
{
	// create a vector for storing the account objects
	vector<Book> myBooks;

	// create three Author objects
	Author p1("J.K.Rowling", "Edinburgh, Scotland");
	Author p2("Suzanne Collins", "Connecticut, USA");
	Author p3("J.R.R. Tolkien", "Bournmouth, England");

	// Create three Book objects
	Book b1(p1, "Harry Potter and the Sorcerer's Stone", 256, 24.95);
	Book b2(p2, "Mockingjay", 400, 12.99);
	Book b3(p3, "The Hobbit", 322, 14.29);

	// add the books to the vector
	myBooks.push_back(b1);
	myBooks.push_back(b2);
	myBooks.push_back(b3);

	// write the books to a file
	// the file will be in the same folder as the executable file
	// assume that the file opens
	ofstream outputFile;
	outputFile.open("bookData.txt");

	for (unsigned i = 0; i < myBooks.size(); ++i)
	{
		myBooks[i].writeData(outputFile);
	}
}

void readTestFile()
{
	vector<Book> myBooks;

	ifstream reader;

	try {
		openFile(reader, "bookData.txt");
	}
	catch (Exception * e) {
		e->check();
		return;
	}

	while (!reader.eof()) {
		Book newBook;

		try {
			newBook.readData(reader);
		}
		catch (Exception e) {
			e.check();
		}

		myBooks.push_back(newBook);

		reader.peek();
	}
	displayBooks(myBooks);
}

void openFile(ifstream& in, const string& _name)
{
	in.open(_name);

	if (in.fail()) {
		throw new Exception(2);
	}
}