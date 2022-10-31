#pragma once
#include <stdio.h>
#include <iostream>
#include "Controller.h"
#include <string>
#include<conio.h>
#include "AdminProgram.h"
using namespace std;


//회원가입
//로그인
//티켓예매 (로그인, 비회원 택 1) -> 영화선택 -> 시간선택 -> 예매할 좌석 인원 선택 (어른 1 아이1 ...) -> 좌석 선택 -> 결제방식 선택 -> 포인트 사용여부체크 (얼마 사용할 건지) -> 결제 금액 출력 ->예매 정보 출력 후 초기화면으로
//예매 취소 (취소할 티켓 선택) ->포인트 복구 후 초기화면.
//예매정보 보기 (로그인, 비회원 택 1) -> 비회원의 경우는 전화번호 입력으로 대체.



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

