#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Book
{
private:
	char author[256];
	char header[256];
	char ganre[64];
	char resume[1024];
	size_t year;
	char keywords[128];
	double rating;
	size_t ID;

public:
	//Canonic
	Book();
	Book(const char* author, const char* header, const char* ganre, const char* resume, size_t year, const char* keywords, double rating, size_t ID);
	ofstream& saveBook(ofstream& os);
	ifstream& readBook(ifstream& is);
public:
	//Setters
	void setAuthor(const char* author);
	void setHeader(const char* header);
	void setGanre(const char* ganre);
	void setResume(const char* resume);
	void setKeywords(const char* keywords);
	void setYear(size_t year);
	void setID(size_t ID); 
	void setRating(double rating);

	//Getters
	const char* getAuthor()const;
	const char* getHeader()const; 
	const char* getGanre()const; 
	const char* getResume()const; 
	const char* getKeywords()const; 
	size_t getYear()const;
	size_t getID()const;
	double getRating()const;
	void printBook();

};
