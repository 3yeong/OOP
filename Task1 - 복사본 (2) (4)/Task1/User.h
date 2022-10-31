#pragma once
#include <string>
#include "Seat.h"
#include "Ticket.h"
using namespace std;




//회원 정보 class
//id, password 입력 양식에 대한 validation 구현해야함.
//password는 password encryption.
class User
{
public:

	   
	string name;
	string phoneNumber;
	string id;
	string password;

	int ticket_count;
	//최대 10장까지 예매 가능하다고 임의로 설정함.
	Ticket ticket[10];


	int point;




	User();
	User(string name, string phoneNumber, string id, string password);
	~User();
};

