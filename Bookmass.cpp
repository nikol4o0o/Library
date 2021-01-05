#include "Bookmass.h"

void Bookmass::erase()
{
	delete[] this->books;
}

void Bookmass::copy(const Bookmass& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->books = new Book[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		this->books[i] = other.books[i];
	}
}

void Bookmass::resize()
{
	this->capacity *= 2;
	Book* temp = new Book[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->books[i];
	}
	this->erase();
	this->books = temp;
}


Bookmass::Bookmass()
{
	this->size = 0;
	this->capacity = 16;
	this->books = new Book[this->capacity];
}

Bookmass::Bookmass(const Bookmass& other)
{
	this->copy(other);
}

Bookmass& Bookmass::operator=(const Bookmass& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

Book& Bookmass::operator[](int i)const
{
	if (i >= 0)
	{
		return books[i];
	}
}
	
Bookmass& Bookmass::AddBook(const Book& newBook)
{
	if (this->size >= this->capacity)
	{
		this->resize();
	}
	this->books[size++] = newBook;
	return *this;
}
Bookmass& Bookmass::RemoveBook(const char* header)
{
	if (size > 0)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (strcmp(books[i].getHeader(), header) == 0)
			{
				for (int j = i; j < this->size - 1; j++)
				{
					books[j] = books[j + 1];
				}
			}
		}
		size--;
	}
		return *this;
}

void Bookmass::SortBooksbyAuthor()
{
	Bookmass sortedbooks;
	for (int j = 0; j <= this->size; j++) {
		for (int i = 0; i < this->size - 1; i++)
		{
			if (strcmp(books[i].getAuthor(), books[i + 1].getAuthor()) > 0)
			{
				sortedbooks[0] = books[i];
				books[i] = books[i + 1];
				books[i + 1] = sortedbooks[0];
			}
		}
	}
}

void Bookmass::SortBooksbyHeader()
{
	Bookmass sortedbooks;
	for (int j = 0; j <= this->size; j++) {
		for (int i = 0; i < this->size - 1; i++)
		{
			if (strcmp(books[i].getHeader(), books[i + 1].getHeader()) > 0)
			{
				sortedbooks[0] = books[i];
				books[i] = books[i + 1];
				books[i + 1] = sortedbooks[0];
			}
		}
	}
}

void Bookmass::SortBooksbyYear()
{
	Bookmass sortedbooks;
	for (int j = 0; j <= this->size; j++) {
		for (int i = 0; i < this->size - 1; i++)
		{
			if (books[i].getYear()>books[i+1].getYear())
			{
				sortedbooks[0] = books[i];
				books[i] = books[i + 1];
				books[i + 1] = sortedbooks[0];
			}
		}
	}
}

void Bookmass::SortBooksbyRating()
{
	Bookmass sortedbooks;
	for (int j = 0; j <= this->size; j++) {
		for (int i = 0; i < this->size - 1; i++)
		{
			if (books[i].getRating() > books[i + 1].getRating())
			{
				sortedbooks[0] = books[i];
				books[i] = books[i + 1];
				books[i + 1] = sortedbooks[0];
			}
		}
	}
}

void Bookmass::printByOrder(const char* order)
{
	if (strcmp(order, "ascending") == 0)
	{
		for (int i = 0; i < this->size; i++)
		{
			books[i].printBook();
		}
	}
	else if(strcmp(order, "descending") == 0)
	{
		for (int i = this->size - 1 ; i >= 0; i--)
		{
			books[i].printBook();
		}
	}
}

ofstream& Bookmass::saveBooks(ofstream& out)
{
	if (out.is_open())
	{
		out << this->size << endl;
		for (int i = 0; i < this->size; i++)
		{
			this->books[i].saveBook(out);
		}
	}
	return out;
}

ifstream& Bookmass::readBooks(ifstream& in)
{
	int size = 0;
	in >> size;
	for (int i = 0; i < size; i++)
	{
		Book book;
		book.readBook(in);
		this->AddBook(book);
	}
	return in;
}

void Bookmass::BookPrintByID(size_t ID)const
{
	bool flag = false;
	for (int i = 0; i < this->size; i++)
	{
		if (books[i].getID() == ID)
		{
			books[i].printBook();
			flag = true;
		}
	}
	if (!flag)
	{

		cout << "No match for ID!" << endl;
	}
}


int Bookmass::getSize()const
{
	return this->size;
}

Bookmass::~Bookmass()
{
	this->erase();
}
