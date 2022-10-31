#include "Data.h"

//data는 정보의 수정이 있을 경우 data.bin으로 실시간 update되기 떄문에 Data 객체 안의 정보들은 모두 힙영역을 사용하지 스택영역만을 사용함.

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