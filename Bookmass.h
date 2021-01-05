#pragma once
#include <iostream>
#include <fstream>
#include "Book.h"

using namespace std;

class Bookmass
{
private:
	Book* books;
	int size;
	int capacity;
private:
	void copy(const Bookmass& other);
	void resize();
	void erase();
public:
	//Canonic
	Bookmass();
	Bookmass(const Bookmass& other);
	Bookmass& operator=(const Bookmass& other);
	Book& operator[](int i)const;
	~Bookmass();
public:
	//Additional
	Bookmass& AddBook(const Book& newBook);
	Bookmass& RemoveBook(const char* header);
	void SortBooksbyAuthor();
	void SortBooksbyHeader();
	void SortBooksbyYear();
	void SortBooksbyRating();
	void BookPrintByID(size_t ID)const;
	ofstream& saveBooks(ofstream& out);
	ifstream& readBooks(ifstream& in);
	int getSize()const;
	void printByOrder(const char* order);
};