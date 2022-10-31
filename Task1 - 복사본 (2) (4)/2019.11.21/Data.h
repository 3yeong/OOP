#pragma once
#include "Movie.h"
#include "Theater.h"
#include "ShowingInfo.h"
#include <map>
using namespace std;



class Data
{
public:

	static int movie_count;
	static int theater_count;
	static int showingInfo_count;	//현재까지 저장된 상영정보 수
	Movie movie_list[20];	//key = title, value = Movie객체
	Theater theater_list[20];	//key = 상영관넘버, value = Theater 객체.
	ShowingInfo showingInfo_list[20];


	Data();
	~Data();

	void add_Movie(Movie _movie);
	void add_Theater(Theater _theater);
	void add_ShowingInfo(ShowingInfo _showingInfo);
};

