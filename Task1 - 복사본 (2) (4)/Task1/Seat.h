#pragma once
#include <string>
using namespace std;

class Seat {

public:
	int row;		//¡Ÿ (A, B, C ...)
	int col;		//ø≠ (1, 2, 3 ...)
	int isbooked;
	int isSelected;


public:
	Seat();
	Seat(int row, int col);
	~Seat();
	void set_isbooked(int n);
	void set_isSelected(bool b);
};