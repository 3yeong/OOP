#include "ShowingInfo.h"
#include <iostream>



ShowingInfo::ShowingInfo(string title, int number_of_theater, string starttime)
{
	this->starttime = starttime;
	this->title = title;
	this->number_of_theater = number_of_theater;
}
ShowingInfo::ShowingInfo()
{

}



ShowingInfo::~ShowingInfo()
{
}

int ShowingInfo::setSeat(int i, int j, int row, int col) {
	
	
	
	Seat s = Seat();
	s.row = i;
	s.col = j;
	i = i + 1;
	int n = (i - 1)*col + j;
	seat[n] = s;



	return n;
}


Seat ShowingInfo::getSeat(int i, int j, int row, int col) {

	i = i + 1;
	
	int n = (i - 1)*col + j;
	return seat[n];
}
