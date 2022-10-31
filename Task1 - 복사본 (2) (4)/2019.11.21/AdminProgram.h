#pragma once
#include <string>
using namespace std;
#include "Controller.h"
#include <iostream>


class AdminProgram
{

private:

	Controller* controller;


public:




	//��ȭ �߰�
	void addMovie();
	void showMovie();
	void deleteMovie();

	//���� �߰�
	void addTheater();

	//������ �߰�
	void addShowingInfo();



	AdminProgram();	//������. ȣ��� binary ������ �о�ͼ� (Movie, Theater, ShowingInfo) �ʵ尪�� �ʱ�ȭ ����.
	~AdminProgram();
};

