#pragma once
#include <stdio.h>
#include <iostream>
#include "Controller.h"
#include <string>
#include<conio.h>
#include "AdminProgram.h"
using namespace std;


//ȸ������
//�α���
//Ƽ�Ͽ��� (�α���, ��ȸ�� �� 1) -> ��ȭ���� -> �ð����� -> ������ �¼� �ο� ���� (� 1 ����1 ...) -> �¼� ���� -> ������� ���� -> ����Ʈ ��뿩��üũ (�� ����� ����) -> ���� �ݾ� ��� ->���� ���� ��� �� �ʱ�ȭ������
//���� ��� (����� Ƽ�� ����) ->����Ʈ ���� �� �ʱ�ȭ��.
//�������� ���� (�α���, ��ȸ�� �� 1) -> ��ȸ���� ���� ��ȭ��ȣ �Է����� ��ü.



class UserProgram{

private:

	Controller* controller;

public:
	bool user();
	void find();
	void sign_up();
	bool log_inout();
	void ticketing();
	void cancel();
	void show_ticket();
	string* seat(int num);



	string input_phoneNum();


	string encrypt(std::string password, std::string key);
	string decrypt(std::string password, std::string key);

	string input_password();
	void showUserInfo();

	UserProgram();
	~UserProgram();
};

