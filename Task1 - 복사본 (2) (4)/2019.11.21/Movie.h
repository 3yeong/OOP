#pragma once
#include <string>
using namespace std;


class Movie
{
public:
	string title;			//����
	string release_date;	//��������
	string showtime;		//�󿵽ð� (ex 100��)
	string old;			//���� ����


	Movie();
	Movie(string title, string release_date, string showtime, string old);
	~Movie();
};

