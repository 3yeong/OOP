#include "Seat.h"



Seat::Seat(int row, int col)
{
		
		this->row =  row ;
		this->col = col;			//�ش� �¼��� ��
		this->isbooked = false;		//�ʱ�ȭ. ���ŵ� �¼��� ��� true�� ����.
		this->isSelected = false;
}


Seat::~Seat()
{
}
Seat::Seat() {}

void Seat::set_isbooked(bool b) {
	this->isbooked = b;
}
void Seat::set_isSelected(bool b) {
	this->isSelected = b;
}