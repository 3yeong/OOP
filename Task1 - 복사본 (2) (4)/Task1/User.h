#pragma once
#include <string>
#include "Seat.h"
#include "Ticket.h"
using namespace std;




//ȸ�� ���� class
//id, password �Է� ��Ŀ� ���� validation �����ؾ���.
//password�� password encryption.
class User
{
public:

	   
	string name;
	string phoneNumber;
	string id;
	string password;

	int ticket_count;
	//�ִ� 10����� ���� �����ϴٰ� ���Ƿ� ������.
	Ticket ticket[10];


	int point;




	User();
	User(string name, string phoneNumber, string id, string password);
	~User();
};

