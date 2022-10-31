#include "User.h"



User::User()
{
}

User::User(string name, string phoneNumber, string id, string password) {
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->id = id;
	this->password = password;
	this->ticket_count = 0;
	this->point = 0;
}



User::~User()
{
}
