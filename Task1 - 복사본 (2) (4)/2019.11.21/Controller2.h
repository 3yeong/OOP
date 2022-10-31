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

	User* currentUser;	//현재 로그인 되어있는 유저.
	UserData* userdata;



	void pay_for_ticket(int amount_of_payment);
	ShowingInfo selectShowingInfo();	//상영정보를 선택하면 그 정보를 take_ticket()으로 넘겨줄것임.
	Ticket make_ticket();	//selectShowingInfo()로 부터 받아온	showingInfo객체와 콘솔(UserProgram)으로 부터 받아온 인원 정보를 바탕으로 
	void take_ticket();		//User에 ticket을 저장하고.
	void return_ticket();	
	string show_ticket();	//예매정보를 string형태로 return함. 출력은 UserProgram에서 이루어 질 것임.





	Controller2();
	~Controller2();
};

