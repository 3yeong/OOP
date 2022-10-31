#pragma once
#include "User.h"
#include "UserUnknown.h"

class UserData
{
public:

	int user_count;
	int userUnknown_count;
	User user[100];
	UserUnknown userUknown[100];

	UserData();
	~UserData();
};

