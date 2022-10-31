#pragma once
#include <string>
#include "Theater.h"
#include "Seat.h"
#include <vector>
using namespace std;





class ShowingInfo	//상영정보. 
{
		
public:
	string title;				//영화 제목. 이를 이용해서 Movie클래스에서 영화 정보를 가져올것임.
	Seat seat[1000];		//Seat 배열. 상영관 번호를 이용해서 Theater 클래스에서 좌석수를 가져온 후에 Seat배열을 생성함. 이차원 배열임.
	int number_of_theater;
	string starttime;
	


public:
	ShowingInfo( string title, int number_of_theater, string starttime);
	ShowingInfo();
	~ShowingInfo();
	int setSeat(int i, int j, int row, int col);
	Seat getSeat(int i, int j, int row, int col);
	
};

