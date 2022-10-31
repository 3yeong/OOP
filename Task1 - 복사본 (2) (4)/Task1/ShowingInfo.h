#pragma once
#include <string>
#include "Theater.h"
#include "Seat.h"
#include <vector>
using namespace std;





class ShowingInfo	//������. 
{
		
public:
	string title;				//��ȭ ����. �̸� �̿��ؼ� MovieŬ�������� ��ȭ ������ �����ð���.
	Seat seat[1000];		//Seat �迭. �󿵰� ��ȣ�� �̿��ؼ� Theater Ŭ�������� �¼����� ������ �Ŀ� Seat�迭�� ������. ������ �迭��.
	int number_of_theater;
	string starttime;
	


public:
	ShowingInfo( string title, int number_of_theater, string starttime);
	ShowingInfo();
	~ShowingInfo();
	int setSeat(int i, int j, int row, int col);
	Seat getSeat(int i, int j, int row, int col);
	
};

