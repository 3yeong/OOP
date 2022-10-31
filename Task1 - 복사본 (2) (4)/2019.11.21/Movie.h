#pragma once
#include <string>
using namespace std;


class Movie
{
public:
	string title;			//제목
	string release_date;	//개봉일자
	string showtime;		//상영시간 (ex 100분)
	string old;			//제한 연령


	Movie();
	Movie(string title, string release_date, string showtime, string old);
	~Movie();
};

