#include "Data.h"

//data�� ������ ������ ���� ��� data.bin���� �ǽð� update�Ǳ� ������ Data ��ü ���� �������� ��� �������� ������� ���ÿ������� �����.

int Data::showingInfo_count = 0;
int Data::theater_count = 0;
int Data::movie_count = 0;

Data::Data(){
}


Data::~Data()
{
}

void Data::add_Movie(Movie _movie) {

	this->movie_list[movie_count] = _movie;
	movie_count = movie_count + 1;

}

void Data::add_Theater(Theater _theater) {
	this->theater_list[theater_count] = _theater;
	theater_count++;
}

void Data::add_ShowingInfo(ShowingInfo _showingInfo) {
	this->showingInfo_list[showingInfo_count] = _showingInfo;
}