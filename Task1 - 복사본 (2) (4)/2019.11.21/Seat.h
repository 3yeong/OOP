#pragma once
#include <string>
using namespace std;

class Seat {

public:
	int row;		//�� (A, B, C ...)
	int col;		//�� (1, 2, 3 ...)
	bool isbooked;
	bool isSelected;


public:
	Seat();
	Seat(int row, int col);
	~Seat();
	void set_isbooked(bool b);
	void set_isSelected(bool b);
};