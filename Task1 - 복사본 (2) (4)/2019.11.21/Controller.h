#pragma once
#include <string>
#include "Data.h"
using namespace std;

class Controller
{
public:

	Data d;
	Data* data;
	Controller();
	~Controller();

	void addMovie(string title, string release_date, string showtime, string old);
	void addTheater(int num_of_theater, int row, int col);
	void addShowingInfo(string title, int num_of_theater);
	void showMovieList();

	void deleteMovie(string title);
	//void deleteTheater(int num_of_theater);
	//void deleteShowingInfo(string title, int num_of_theeater);


	void dataRead();
	void dataWrite(Data* data);
};

