#include "Movie.h"


Movie::Movie() {
	
}
Movie::Movie(string title, string release_date, string showtime, int age) {
	this->title = title;
	this->release_date = release_date;
	this->showtime = showtime;
	this->age = age;
}


Movie::~Movie()
{
}
