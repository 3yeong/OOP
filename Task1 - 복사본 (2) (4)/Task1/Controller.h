#pragma once
#include <string>
#include "Data.h"
#include "UserData.h"
#include <fstream>
#include <time.h>
using namespace std;

class Controller
{
public:


	//Controller1
	Data d;
	Data* data;
	Controller();
	~Controller();

	Data* getdata();

	bool addMovie(string title, string release_date, string showtime, int age);
	void showMovieList();
	bool deleteMovie(string title);

	string search_ticketNumber(string phone);

	bool addTheater(int num_of_theater, int row, int col);
	void deleteTheater(int num_of_theater);
	void showTheater();


	
	int addShowingInfo(string title, int num_of_theater, string strattime);
	void deleteShowingInfo(string title, int num_of_theeater, string starttime);
	void deleteShowingInfoAuto(string starttime);
	void deleteShowingInfo(int num_for_delete);
	void showShowingInfo();
	bool showShowingInfo(string title);
	bool screen_num(string title, int num);


	void dataRead();
	void dataWrite(Data* data);







	//Controller2


	User* currentUser;	//현재 로그인 되어있는 유저.


	UserData* userdata;

	void showSeat(int i);
	
	Ticket makeTicket(int kid, int adult, int i, int n, string *seat);
	void bookTicket(int kid, int adult, int i, int n, string *seat);
	void payticket(int method, int amount, Ticket ticket);
	void payticketForUnknown(int method, int amount, Ticket ticket);




	bool return_ticket(string ticketNum);
	bool return_ticket(int ticketNum);


	bool log_in(string id, string pw);
	bool sign_in(string name, string ph, string id, string pw);




	void userdataRead();
	void userdataWrite(UserData* userdata);




	bool isSelected(int i, int n, string *seat);
	bool isBooked(int i, int n, string *seat);

	Ticket search_ticket(string ticketNumber);
	int ageCheck(string title);
};

