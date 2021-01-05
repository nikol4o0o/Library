#include "Book.h"
#include <cstring>

Book::Book()
{
	setAuthor("");
	setHeader("");
	setGanre("");
	setKeywords("");
	setResume("");
	setYear(1);
	setID(1);
	setRating(0);
}

Book::Book(const char* author, const char* header, const char* ganre, const char* resume, size_t year, const char* keywords, double rating, size_t ID)
{
	setAuthor(author);
	setHeader(header);
	setGanre(ganre);
	setKeywords(keywords);
	setResume(resume);
	setYear(year);
	setRating(rating);
	setID(ID);
}


ofstream& Book::saveBook(ofstream& os)
{
	if (os.is_open())
	{
		os << strlen(this->author) << " ";
		os << this->author << endl;
		os << strlen(this->header) << " ";
		os << this->header << endl;
		os << strlen(this->ganre) << " ";
		os << this->ganre << endl;
		os << strlen(this->resume) << " ";
		os << this->resume << endl;
		os << strlen(this->keywords) << " ";
		os << this->keywords << endl;
		os << this->year << endl;
		os << this->rating << endl;
		os << this->ID << endl;
	}
	else
	{
		cout << "Cannot open stream for saving book!" << endl;
	}
	return os;
}

ifstream& Book::readBook(ifstream& is)
{
	if (is.is_open())
	{
		int AuthorLength = 0;
		int HeaderLength = 0;
		int GanreLength = 0;
		int ResumeLength = 0;
		int KeywordsLength = 0;

		is >> AuthorLength;
		is.seekg(1, ios::cur);
		is.getline(this->author, AuthorLength + 1);
		is >> HeaderLength;
		is.seekg(1, ios::cur);
		is.getline(this->header, HeaderLength + 1);
		is >> GanreLength;
		is.seekg(1, ios::cur);
		is.getline(this->ganre, GanreLength + 1);
		is >> ResumeLength;
		is.seekg(1, ios::cur);
		is.getline(this->resume, ResumeLength + 1);
		is >> KeywordsLength;
		is.seekg(1, ios::cur);
		is.getline(this->keywords, KeywordsLength + 1);
		//is.seekg(1, ios::cur);
		is >> this->year;
		//is.seekg(1, ios::cur);
		is >> this->rating;
		//is.seekg(1, ios::cur);
		is >> this->ID;
		//is.seekg(1, ios::cur);*/
	}
	return is;
}

void Book::setAuthor(const char* author)
{
	strcpy_s(this->author, 256, author);
}

void Book::setHeader(const char* header)
{
	strcpy_s(this->header, 256, header);
}

void Book::setGanre(const char* ganre)
{
	strcpy_s(this->ganre, 64, ganre);
}

void Book::setKeywords(const char* keywords)
{
	strcpy_s(this->keywords, 128, keywords);
}

void Book::setResume(const char* resume)
{
	
	strcpy_s(this->resume, 1024, resume);
}

void Book::setYear(size_t year)
{
	this->year = year;
}

void Book::setID(size_t ID)
{
	this->ID = ID;
}

void Book::setRating(double rating)
{
	this->rating = rating;
}

const char* Book::getAuthor()const
{
	return this->author; 
}

const char* Book::getHeader()const
{
	return this->header;
}

const char* Book::getGanre()const
{
	return this->ganre;
}

const char* Book::getKeywords()const
{
	return this->keywords;
}

const char* Book::getResume()const
{
	return this->resume;
}

size_t Book::getYear()const
{
	return this->year;
}

size_t Book::getID()const
{
	return this->ID;
}

double Book::getRating()const
{
	return this->rating;
}

void Book::printBook()
{
	cout << "Author: " << this->author << endl;
	cout << "Header: " << this->header << endl;
	cout << "Ganre: " << this->ganre << endl;
	cout << "Resume: " << this->resume << endl;
	cout << "Year: " << this->year << endl;
	cout << "Keywords: " << this->keywords << endl;
	cout << "Rating: " << this->rating << endl;
	cout << "ID: " << this->ID << endl;
}


