#include "User.h"

User::User()
{
	setUsername("");
	setPassword("");
	setisAdmin(false);
}

User::User(const char* username, const char* password)
{
	setUsername(username);
	setPassword(password);
	setisAdmin(false);
}

User::User(const char* username, const char* password, bool isAdmin)
{
	setUsername(username);
	setPassword(password);
	setisAdmin(isAdmin);
}

ofstream& User::saveUser(ofstream& os)
{
		if (os.is_open())
		{
			os << this->username << endl;
			os << this->password << endl;
		}
		else
		{
			cout << "Cannot open stream for saving user!" << endl;
		}
		return os;
}

ifstream& User::readUser(ifstream& is)
{
	if (is.is_open())
	{
		is >> this->username;
		is >> this->password;
	}
	return is;

}

const char* User::getUsername()const
{
	return this->username;
}

const char* User::getPassword()const
{
	return this->password;
}

bool User::getisAdmin()const
{
	return this->isAdmin;
}

void User::setUsername(const char* username)
{
	strcpy_s(this->username, strlen(username) + 1, username);
}

void User::setPassword(const char* password)
{
	strcpy_s(this->password, strlen(password) + 1, password);
}
void User::setisAdmin(bool isAdmin)
{
	this->isAdmin = isAdmin;
}