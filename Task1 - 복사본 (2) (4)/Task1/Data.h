#pragma once
#include "Movie.h"
#include "Theater.h"
#include "ShowingInfo.h"
#include <map>
using namespace std;



class Data
{
public:

	int movie_count;
	int theater_count;
	int showingInfo_count;	//현재까지 저장된 상영정보 수
	Movie movie_list[20];	//key = title, value = Movie객체
	Theater theater_list[20];	//key = 상영관넘버, value = Theater 객체.
	ShowingInfo showingInfo_list[40];


	Data();
	~Data();

	void delete_Movie(string title);
	bool add_Movie(Movie _movie);


	void add_Theater(Theater _theater);
	void delete_Theater(int num_of_theater);
	Theater getTheater(int num_of_theater);



	void add_ShowingInfo(ShowingInfo _showingInfo);
	void delete_ShowingInfo(string title, int num_of_theater, string starttime);
	void delete_ShowingInfo(string title);
	void delete_ShowingInfo(int num_for_delete);
};

