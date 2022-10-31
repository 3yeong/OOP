#include "Seat.h"



Seat::Seat(int row, int col)
{
		
		this->row =  row ;
		this->col = col;			//해당 좌석의 열
		this->isbooked = 0;		//초기화. 예매된 좌석일 경우 true로 변경.
		this->isSelected = 0;
}


Seat::~Seat()
{
}
Seat::Seat() {
	this->isbooked = 0;		//초기화. 예매된 좌석일 경우 true로 변경.
	this->isSelected = 0;
}
void Seat::set_isbooked(int n) {
	this->isbooked = n;
}