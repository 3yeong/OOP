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

	//��ȭ �߰�
	void addMovie();
	void showMovie();
	void deleteMovie();

	//���� �߰�
	void addTheater();
	void showTheater();
	void deleteTheater();

	//������ �߰�
	void addShowingInfo();
	void showShowingInfo();
	void deleteShowingInfo();
	void checkShowingInfo();
	void remove(string a);
	string input_starttime();
	string remove_starttime(string &a);



	AdminProgram();	//������. ȣ��� binary ������ �о�ͼ� (Movie, Theater, ShowingInfo) �ʵ尪�� �ʱ�ȭ ����.
	~AdminProgram();
};

