#include "AdminProgram.h"


/*

�߰� ������ �κ� :
1) ��� �޼ҵ忡�� �Է½� ������ �ȸ��� ���.
2) string�� ��� ���� �Է½� ���� �����ϰ� ����.




*/



AdminProgram::AdminProgram()
{
	this->controller = new Controller();
}


AdminProgram::~AdminProgram()
{
}




//�ܼ��� ���� �Է��� �޾Ƽ� Controller::addMovie() ȣ��
void AdminProgram::addMovie() {

	//�ܼ� �Է� (����, ��������, ������, �帣 => string)
	string title;
	string release_date;
	string showtime;
	string old;

	std::cout << "���� : ";
	std::cin >> title;
	
	std::cout << "�������� : " ;
	std::cin >> release_date;

	std::cout << "�󿵽ð� : " ;
	std::cin >> showtime;

	std::cout << "���ѿ��� : " ;
	std::cin >> old;


	//Controller::addMovie() ȣ��
	controller->addMovie(title, release_date, showtime, old);


}
void AdminProgram::deleteMovie() {
	string title;
	std::cout << "���� : ";
	std::cin >> title;

	controller->deleteMovie(title);
}
void AdminProgram::showMovie() {
	controller->showMovieList();
}



//�ܼ��� ���� �Է��� �޾Ƽ� �������� ����
void AdminProgram::addTheater() {

	//�ܼ� �Է�
	//Controller::addTheater() ȣ��
	int num_of_theater;
	int row;
	int col;

	std::cout << "�󿵰� ��ȣ : ";
	std::cin >> num_of_theater;

	std::cout << "row : ";
	std::cin >> row;

	std::cout << "col : ";
	std::cin >> col;


	//Controller::addMovie() ȣ��
	controller->addTheater(num_of_theater,row, col);



}

void AdminProgram::addShowingInfo() {

	//�ܼ� �Է�
	//Controller::addShowingInfo() ȣ��
	int num_of_theater;
	string title;

	std::cout << "�󿵰� ��ȣ : ";
	std::cin >> num_of_theater;

	std::cout << "��ȭ ���� : ";
	std::cin >> title;



	//Controller::addMovie() ȣ��
	controller->addShowingInfo(title,num_of_theater);

}