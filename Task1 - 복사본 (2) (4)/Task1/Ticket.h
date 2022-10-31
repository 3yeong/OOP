#pragma once
#include "Seat.h"
#include "Payment.h"
#include <string>
using namespace std;



class Ticket
{
public:

	string thicketNUmber;
	string phoneNumber;

	int numOfShowinginfo;
	int adult;	//성인 인원
	int child;	//청소년 인원
	int total_num;	//전체 인원 (adult + child)


	string seat[10];	//한번에 예매 가능한 인원. 청소년 5, 성인 5.


	Payment payment;
	//string ticketNumber;	//예매시각 + 상영정보index + seat index

	


	Ticket();
	~Ticket();
};


