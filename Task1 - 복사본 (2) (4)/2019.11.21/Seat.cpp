#include "Seat.h"



Seat::Seat(int row, int col)
{
		
		this->row =  row ;
		this->col = col;			//해당 좌석의 열
		this->isbooked = false;		//초기화. 예매된 좌석일 경우 true로 변경.
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