#pragma once
#include <string>
using namespace std;


class Movie
{
public:
	string title;			//����
	string release_date;	//��������
	string showtime;		//�󿵽ð� (ex 100��)
	int age;				//���� ����


	Movie();
	Movie(string title, string release_date, string showtime, int old);
	~Movie();
};

