#pragma once
#include "Seat.h"
#include "Payment.h"
#include <string>
using namespace std;



class Ticket
{
public:


	int adult;	//���� �ο�
	int child;	//û�ҳ� �ο�
	int total_num;	//��ü �ο� (adult + child)

	Seat seat[10];	//�ѹ��� ���� ������ �ο�. û�ҳ� 5, ���� 5.

	Payment payment;
	string ticketNumber;	//���Žð� + ������index + seat index

	


	Ticket();
	~Ticket();
};

