#include "Data.h"
#include <iostream>

//data는 정보의 수정이 있을 경우 data.bin으로 실시간 update되기 떄문에 Data 객체 안의 정보들은 모두 힙영역을 사용하지 스택영역만을 사용함.



Data::Data(){
}


Data::~Data()
{
}



void Data::delete_Movie(string title) {

	for (int i = 0; i < movie_count; i++) {
		if (movie_list[i].title == title) {
			for (int j = i; j < movie_count; j++) {
				movie_list[j] = movie_list[j + 1];
			}
			break;
		}
	}
	movie_count = movie_count - 1;
}
bool Data::add_Movie(Movie _movie) {
	bool check = false;
	for (int i = 0; i < movie_count; i++) {
		if (this->movie_list[i].title==_movie.title) {
			check = true;
			break;
		}
	}

	if (!check) {
		this->movie_list[movie_count] = _movie;
		movie_count = movie_count + 1;
	}

	return check;

}





Theater Data::getTheater(int num_of_theater) {
	for (int i = 0; i < theater_count; i++) {
		if (theater_list[i].num_of_theater == num_of_theater) {
			
			return theater_list[i];
		}
	}
	return theater_list[19];
}

void Data::add_Theater(Theater _theater) {
	this->theater_list[theater_count] = _theater;
	theater_count = theater_count + 1;
}


void Data::delete_Theater(int num_of_theater) {

	for (int i = 0; i < theater_count; i++) {
		if (theater_list[i].num_of_theater == num_of_theater) {
			for (int j = i; j <this->theater_count-1; j++) {
				theater_list[j] = theater_list[j + 1];
			}
			break;
		}
	}
	theater_count = theater_count - 1;
}









void Data::add_ShowingInfo(ShowingInfo _showingInfo) {
	this->showingInfo_list[showingInfo_count] = _showingInfo;
	showingInfo_count = showingInfo_count + 1;
}

void Data::delete_ShowingInfo(string title, int num_of_theater, string starttime) {
	for (int i = 0; i < this->showingInfo_count; i++) {
		if (this->showingInfo_list[i].title == title && this->showingInfo_list[i].number_of_theater == num_of_theater && this->showingInfo_list[i].starttime == starttime) {
			for (int j = i; j < showingInfo_count; j++) {
				showingInfo_list[j] = showingInfo_list[j + 1];
			}
			break;
		}
	}
	showingInfo_count = showingInfo_count - 1;
}

void Data::delete_ShowingInfo(string title) {
	int k = showingInfo_count;
	for (int i = 0; i < k; i++) {
		if (this->showingInfo_list[i].title == title) {
			showingInfo_count = showingInfo_count - 1;
			for (int j = i; j < showingInfo_count; j++) {
				showingInfo_list[j] = showingInfo_list[j + 1];
			}
		}
	}
	
}

void Data::delete_ShowingInfo(int num_for_delete) {
	for (int j = num_for_delete; j < showingInfo_count; j++) {
		showingInfo_list[j] = showingInfo_list[j + 1];
	}
	showingInfo_count = showingInfo_count - 1;
}