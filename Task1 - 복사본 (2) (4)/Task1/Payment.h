#pragma once
#include <string>
using namespace std;

class Payment
{
public:

	int usedPoint;	//결제시 포인트 사용 금액.

	string method_of_payment; //카드, 현금?
	int amount_of_payment; //카드 또는 현금 결제 금액.


	Payment();
	~Payment();
};

