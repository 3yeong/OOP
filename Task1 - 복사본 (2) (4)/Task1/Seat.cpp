#include "Seat.h"



Seat::Seat(int row, int col)
{
		
		this->row =  row ;
		this->col = col;			//�ش� �¼��� ��
		this->isbooked = 0;		//�ʱ�ȭ. ���ŵ� �¼��� ��� true�� ����.
		this->isSelected = 0;
}


Seat::~Seat()
{
}
Seat::Seat() {
	this->isbooked = 0;		//�ʱ�ȭ. ���ŵ� �¼��� ��� true�� ����.
	this->isSelected = 0;
}
void Seat::set_isbooked(int n) {
	this->isbooked = n;
}