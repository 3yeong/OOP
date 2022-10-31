#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include "Data.h"
#include "UserData.h"
#include "UserProgram.h"




class Controller2
{
public:

	User* currentUser;	//���� �α��� �Ǿ��ִ� ����.
	UserData* userdata;



	void pay_for_ticket(int amount_of_payment);
	ShowingInfo selectShowingInfo();	//�������� �����ϸ� �� ������ take_ticket()���� �Ѱ��ٰ���.
	Ticket make_ticket();	//selectShowingInfo()�� ���� �޾ƿ�	showingInfo��ü�� �ܼ�(UserProgram)���� ���� �޾ƿ� �ο� ������ �������� 
	void take_ticket();		//User�� ticket�� �����ϰ�.
	void return_ticket();	
	string show_ticket();	//���������� string���·� return��. ����� UserProgram���� �̷�� �� ����.





	Controller2();
	~Controller2();
};

