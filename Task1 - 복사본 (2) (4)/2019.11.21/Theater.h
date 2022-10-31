#pragma once
#include <string>
using namespace std;
#include "Seat.h"



class Theater
{
	public:
	int num_of_theater;
	int row;
	int col;
	

	Theater();
	Theater(int num_of_theater, int row, int col);
	~Theater();

	
};

