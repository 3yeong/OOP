#pragma once
#include <string>
using namespace std;
#include "Controller.h"
#include <iostream>
#include <algorithm>


class AdminProgram
{

private:

	Controller* controller;


public:


	bool admin();

	//영화 추가
	void addMovie();
	void showMovie();
	void deleteMovie();

	//극장 추가
	void addTheater();
	void showTheater();
	void deleteTheater();

	//상영정보 추가
	void addShowingInfo();
	void showShowingInfo();
	void deleteShowingInfo();
	void checkShowingInfo();
	void remove(string a);
	string input_starttime();
	string remove_starttime(string &a);



	AdminProgram();	//생성자. 호출시 binary 파일을 읽어와서 (Movie, Theater, ShowingInfo) 필드값을 초기화 해줌.
	~AdminProgram();
};

