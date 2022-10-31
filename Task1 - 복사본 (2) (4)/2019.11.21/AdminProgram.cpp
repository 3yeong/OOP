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




//콘솔을 통해 입력을 받아서 Controller::addMovie() 호출
void AdminProgram::addMovie() {

	//콘솔 입력 (제목, 개봉일자, 상영일자, 장르 => string)
	string title;
	string release_date;
	string showtime;
	string old;

	std::cout << "제목 : ";
	std::cin >> title;
	
	std::cout << "개봉일자 : " ;
	std::cin >> release_date;

	std::cout << "상영시간 : " ;
	std::cin >> showtime;

	std::cout << "제한연령 : " ;
	std::cin >> old;


	//Controller::addMovie() 호출
	controller->addMovie(title, release_date, showtime, old);


}
void AdminProgram::deleteMovie() {
	string title;
	std::cout << "제목 : ";
	std::cin >> title;

	controller->deleteMovie(title);
}
void AdminProgram::showMovie() {
	controller->showMovieList();
}



//콘솔을 통해 입력을 받아서 극장정보 저장
void AdminProgram::addTheater() {

	//콘솔 입력
	//Controller::addTheater() 호출
	int num_of_theater;
	int row;
	int col;

	std::cout << "상영관 번호 : ";
	std::cin >> num_of_theater;

	std::cout << "row : ";
	std::cin >> row;

	std::cout << "col : ";
	std::cin >> col;


	//Controller::addMovie() 호출
	controller->addTheater(num_of_theater,row, col);



}

void AdminProgram::addShowingInfo() {

	//콘솔 입력
	//Controller::addShowingInfo() 호출
	int num_of_theater;
	string title;

	std::cout << "상영관 번호 : ";
	std::cin >> num_of_theater;

	std::cout << "영화 제목 : ";
	std::cin >> title;



	//Controller::addMovie() 호출
	controller->addShowingInfo(title,num_of_theater);

}