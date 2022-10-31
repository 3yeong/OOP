#include "AdminProgram.h"


/*

추가 구현할 부분 :
1) 모든 메소드에서 입력시 형식이 안맞을 경우.
2) string의 경우 공백 입력시 공백 제거하고 저장.



*/



AdminProgram::AdminProgram()
{
	this->controller = new Controller();
}


AdminProgram::~AdminProgram()
{
}

bool AdminProgram::admin() {
	while (true) {
		

		int menu;
		cout << "*********** 관리자 프로그램 ************ " << endl << endl;
		cout << "  1. 영화 등록" << endl << "  2. 영화 삭제" << endl << "  3. 등록된 영화정보 출력" << endl << "  4. 상영관 등록" << endl << "  5. 상영관 삭제" << endl << "  6. 등록된 상영관 정보 출력" << endl << "  7. 상영정보 등록" << endl << "  8. 상영정보 삭제" << endl << "  9. 등록된 상영정보 출력" << endl << "  10. 전체 정보보기" << endl << "  11. 예매 현황확인" << endl << "  12. 관리프로그램 종료" << endl;
		
		
		int validation_number = 1;
		while (validation_number != 0) {
			std::cout << endl << " 번호 선택 -> ";
			std::cin >> menu;
			std::cout;

			validation_number = 0;
			if (!cin) {
				std::cout << "숫자만 입력해 주세요" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				validation_number = 1;
			}
		}


		system("cls");

		switch (menu) {
		case 1:
			addMovie();
			break;
		case 2:
			deleteMovie();
			break;
		case 3:
			showMovie();
			break;
		case 4:
			addTheater();
			break;
		case 5:
			deleteTheater();
			break;
		case 6:
			showTheater();
			break;
		case 7:
			cout << "시작시간 입력시 2019년 11월 20일 12시 30분의 경우, 201911201230 형식으로 입력해주십시오" << endl;
			addShowingInfo();
			break;
		case 8:
			deleteShowingInfo();
			break;
		case 9:
			showShowingInfo();
			break;
		case 10:
			showMovie();
			std::cout << endl;
			showTheater();
			std::cout << endl;
			showShowingInfo();
			break;
		case 11:
			checkShowingInfo();
			break;
		case 12:
			return 0;
		default:
			break;
		}
		






	}
	return 0;
}
void AdminProgram::checkShowingInfo() {
	std::cout << "  --------- 예매 현황 조회 ---------" << endl;
	int showingInfoNumber;

	this->showShowingInfo();

	cout << "상영번호 선택 : ";
	cout;
	cin >> showingInfoNumber;
	controller->showSeat(showingInfoNumber-1);

}


//콘솔을 통해 입력을 받아서 Controller::addMovie() 호출
void AdminProgram::addMovie() {

	//콘솔 입력 (제목, 개봉일자, 상영일자, 장르 => string)
	string title;
	string release_date;
	string showtime;
	int age;

	std::cout << "  --------- 영화 등록 ---------"<<endl;
	std::cout << "  제목 : ";
	std::cin >> title;
	
	
	std::cout << "  개봉일자 : " ;
	std::cout;
	std::cin >> release_date;
	std::cout;
	std::cout << "  상영시간 : " ;
	std::cin >> showtime;
	std::cout;
	std::cout << "  제한연령 : " ;
	std::cin >> age;


	//정효인, 영화 제목 중복 체크
	bool check = controller->addMovie(title, release_date, showtime, age);
	if (check) {
		std::cout << "  동일한 영화 제목이 있습니다!" << endl;
	}
	std::cout << "  ------------------------------" << endl;
	


}
void AdminProgram::deleteMovie() {
	string title;
	std::cout << "  --------- 영화 삭제 ---------" << endl;
	std::cout << "  제목 : ";
	std::cin >> title;
	
	cout;
	//효인(7번)
	bool check = controller->deleteMovie(title);
	if (!check) {
		std::cout << "  동일한 영화 제목이 없습니다. 다시 입력해주세요!" << endl;
	}
	std::cout << endl << "  ------------------------------" << endl;
}
void AdminProgram::showMovie() {
	std::cout << "  --------- 영화 정보 ---------" << endl;
	controller->showMovieList();
	std::cout << "  ------------------------------" << endl;
}









//콘솔을 통해 입력을 받아서 극장정보 저장
void AdminProgram::addTheater() {


	//콘솔 입력
	//Controller::addTheater() 호출
	int num_of_theater;
	int row;
	int col;

	std::cout << "  --------- 상영관 등록 ---------" << endl;
	std::cout << "  상영관 번호 : ";
	std::cin >> num_of_theater;
	std::cout;

	std::cout << "  row : ";
	std::cin >> row;
	std::cout;

	std::cout << "  col : ";
	std::cin >> col;
	std::cout << "  ------------------------------" << endl; ;


	//Controller::addMovie() 호출
	bool check_theater = controller->addTheater(num_of_theater, row, col);
	if (check_theater) {
		std::cout << "  동일한 관이 있습니다. 다시 입력해주세요!" << endl;
	}
}

void AdminProgram::deleteTheater() {
	int num_of_theater;

	std::cout << "  --------- 상영관 삭제 ---------" << endl;
	std::cout << "  상영관 번호 : ";
	std::cin >> num_of_theater;
	std::cout;
	controller->deleteTheater(num_of_theater);
	std::cout << "  ------------------------------" << endl; ;
}
void AdminProgram::showTheater() {
	std::cout << "  --------- 상영관 정보 ---------" << endl;
	controller->showTheater();
	std::cout << "  -------------------------------" << endl;
}











void AdminProgram::addShowingInfo() {
	//콘솔 입력
	//Controller::addShowingInfo() 호출
	int num_of_theater;
	string title;
	string starttime;
	int validation;

	std::cout << "  --------- 상영 정보 등록 ---------" << endl;
	this->showMovie();
	std::cout << "  영화 제목 : ";
	
	std::cin >> title;
	std::cout;

	this->showTheater();
	std::cout << "  상영관 번호 : ";
	std::cin >> num_of_theater;
	std::cout;

	

	std::cout << "  상영 시작 시간 : ";
	std::cin >> starttime;
	std::cout << "  -------------------------------" << endl;;

	validation = controller->addShowingInfo(title, num_of_theater, starttime);
	if (validation == 1) {
		std::cout << "  없는 영화제목 입니다. 다시 입력해 주세요!" << endl;
	}
	else if (validation == 2) {
		std::cout << "  없는 상영관 입니다. 다시 입력해 주세요!" << endl;

	}
	else if (validation == 3) {
		std::cout << "  없는 영화제목과 상영관 입니다. 다시 입력해 주세요!" << endl;

	}
}
void AdminProgram::deleteShowingInfo() {
	
	showShowingInfo();
	int num_for_delete;
	std::cout << "  --------- 상영 정보 삭제 ---------" << endl;
	cout << "  삭제할 상영정보 번호 : ";
	cin >> num_for_delete;
	cout;
	std::cout << endl << "  -------------------------------" << endl;

	controller->deleteShowingInfo(num_for_delete);



}
void AdminProgram::showShowingInfo() {
	std::cout << "  ------------------- 상영 정보 --------------------" << endl;
	controller->showShowingInfo();
	std::cout << "  ---------------------------------------------------------" << endl;
}

//이범수, 문자열 공백 제거

void AdminProgram::remove(string a) {
	a.erase(std::remove(a.begin(), a.end(), ' '), a.end());
}




//세영, 상영 시간 입력.
string AdminProgram::remove_starttime(string &a) {
	a.erase(std::remove(a.begin(), a.end(), '.'), a.end());
	a.erase(std::remove(a.begin(), a.end(), ':'), a.end());
	return a;
} //공백제거

string AdminProgram::input_starttime() {
	string starttime;

	cout << "상영시간 2019년 12월 05일 12시30분 = 2019.12.05.12:30 형식으로 입력해주세요" << endl;
	getline(std::cin, starttime);

	starttime = remove_starttime(starttime);

	cout << starttime << endl;

	return starttime;
}
