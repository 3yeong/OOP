#pragma once
#include <string>
using namespace std;

class Payment
{
public:

	int usedPoint;	//������ ����Ʈ ��� �ݾ�.

	string method_of_payment; //ī��, ����?
	int amount_of_payment; //ī�� �Ǵ� ���� ���� �ݾ�.


	Payment();
	~Payment();
};

