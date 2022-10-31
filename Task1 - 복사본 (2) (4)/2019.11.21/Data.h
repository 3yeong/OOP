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
	static int showingInfo_count;	//������� ����� ������ ��
	Movie movie_list[20];	//key = title, value = Movie��ü
	Theater theater_list[20];	//key = �󿵰��ѹ�, value = Theater ��ü.
	ShowingInfo showingInfo_list[20];


	Data();
	~Data();

	void add_Movie(Movie _movie);
	void add_Theater(Theater _theater);
	void add_ShowingInfo(ShowingInfo _showingInfo);
};

