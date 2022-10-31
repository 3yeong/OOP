#include "Movie.h"


Movie::Movie() {
	
}
Movie::Movie(string title, string release_date, string showtime, string old) {
	this->title = title;
	this->release_date = release_date;
	this->showtime = showtime;
	this->old = old;
}


Movie::~Movie()
{
}
