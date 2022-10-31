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

bool AdminProgram::admin() {
	while (true) {
		

		int menu;
		cout << "*********** ������ ���α׷� ************ " << endl << endl;
		cout << "  1. ��ȭ ���" << endl << "  2. ��ȭ ����" << endl << "  3. ��ϵ� ��ȭ���� ���" << endl << "  4. �󿵰� ���" << endl << "  5. �󿵰� ����" << endl << "  6. ��ϵ� �󿵰� ���� ���" << endl << "  7. ������ ���" << endl << "  8. ������ ����" << endl << "  9. ��ϵ� ������ ���" << endl << "  10. ��ü ��������" << endl << "  11. ���� ��ȲȮ��" << endl << "  12. �������α׷� ����" << endl;
		
		
		int validation_number = 1;
		while (validation_number != 0) {
			std::cout << endl << " ��ȣ ���� -> ";
			std::cin >> menu;
			std::cout;

			validation_number = 0;
			if (!cin) {
				std::cout << "���ڸ� �Է��� �ּ���" << endl;
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
			cout << "���۽ð� �Է½� 2019�� 11�� 20�� 12�� 30���� ���, 201911201230 �������� �Է����ֽʽÿ�" << endl;
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
	std::cout << "  --------- ���� ��Ȳ ��ȸ ---------" << endl;
	int showingInfoNumber;

	this->showShowingInfo();

	cout << "�󿵹�ȣ ���� : ";
	cout;
	cin >> showingInfoNumber;
	controller->showSeat(showingInfoNumber-1);

}


//�ܼ��� ���� �Է��� �޾Ƽ� Controller::addMovie() ȣ��
void AdminProgram::addMovie() {

	//�ܼ� �Է� (����, ��������, ������, �帣 => string)
	string title;
	string release_date;
	string showtime;
	int age;

	std::cout << "  --------- ��ȭ ��� ---------"<<endl;
	std::cout << "  ���� : ";
	std::cin >> title;
	
	
	std::cout << "  �������� : " ;
	std::cout;
	std::cin >> release_date;
	std::cout;
	std::cout << "  �󿵽ð� : " ;
	std::cin >> showtime;
	std::cout;
	std::cout << "  ���ѿ��� : " ;
	std::cin >> age;


	//��ȿ��, ��ȭ ���� �ߺ� üũ
	bool check = controller->addMovie(title, release_date, showtime, age);
	if (check) {
		std::cout << "  ������ ��ȭ ������ �ֽ��ϴ�!" << endl;
	}
	std::cout << "  ------------------------------" << endl;
	


}
void AdminProgram::deleteMovie() {
	string title;
	std::cout << "  --------- ��ȭ ���� ---------" << endl;
	std::cout << "  ���� : ";
	std::cin >> title;
	
	cout;
	//ȿ��(7��)
	bool check = controller->deleteMovie(title);
	if (!check) {
		std::cout << "  ������ ��ȭ ������ �����ϴ�. �ٽ� �Է����ּ���!" << endl;
	}
	std::cout << endl << "  ------------------------------" << endl;
}
void AdminProgram::showMovie() {
	std::cout << "  --------- ��ȭ ���� ---------" << endl;
	controller->showMovieList();
	std::cout << "  ------------------------------" << endl;
}









//�ܼ��� ���� �Է��� �޾Ƽ� �������� ����
void AdminProgram::addTheater() {


	//�ܼ� �Է�
	//Controller::addTheater() ȣ��
	int num_of_theater;
	int row;
	int col;

	std::cout << "  --------- �󿵰� ��� ---------" << endl;
	std::cout << "  �󿵰� ��ȣ : ";
	std::cin >> num_of_theater;
	std::cout;

	std::cout << "  row : ";
	std::cin >> row;
	std::cout;

	std::cout << "  col : ";
	std::cin >> col;
	std::cout << "  ------------------------------" << endl; ;


	//Controller::addMovie() ȣ��
	bool check_theater = controller->addTheater(num_of_theater, row, col);
	if (check_theater) {
		std::cout << "  ������ ���� �ֽ��ϴ�. �ٽ� �Է����ּ���!" << endl;
	}
}

void AdminProgram::deleteTheater() {
	int num_of_theater;

	std::cout << "  --------- �󿵰� ���� ---------" << endl;
	std::cout << "  �󿵰� ��ȣ : ";
	std::cin >> num_of_theater;
	std::cout;
	controller->deleteTheater(num_of_theater);
	std::cout << "  ------------------------------" << endl; ;
}
void AdminProgram::showTheater() {
	std::cout << "  --------- �󿵰� ���� ---------" << endl;
	controller->showTheater();
	std::cout << "  -------------------------------" << endl;
}











void AdminProgram::addShowingInfo() {
	//�ܼ� �Է�
	//Controller::addShowingInfo() ȣ��
	int num_of_theater;
	string title;
	string starttime;
	int validation;

	std::cout << "  --------- �� ���� ��� ---------" << endl;
	this->showMovie();
	std::cout << "  ��ȭ ���� : ";
	
	std::cin >> title;
	std::cout;

	this->showTheater();
	std::cout << "  �󿵰� ��ȣ : ";
	std::cin >> num_of_theater;
	std::cout;

	

	std::cout << "  �� ���� �ð� : ";
	std::cin >> starttime;
	std::cout << "  -------------------------------" << endl;;

	validation = controller->addShowingInfo(title, num_of_theater, starttime);
	if (validation == 1) {
		std::cout << "  ���� ��ȭ���� �Դϴ�. �ٽ� �Է��� �ּ���!" << endl;
	}
	else if (validation == 2) {
		std::cout << "  ���� �󿵰� �Դϴ�. �ٽ� �Է��� �ּ���!" << endl;

	}
	else if (validation == 3) {
		std::cout << "  ���� ��ȭ����� �󿵰� �Դϴ�. �ٽ� �Է��� �ּ���!" << endl;

	}
}
void AdminProgram::deleteShowingInfo() {
	
	showShowingInfo();
	int num_for_delete;
	std::cout << "  --------- �� ���� ���� ---------" << endl;
	cout << "  ������ ������ ��ȣ : ";
	cin >> num_for_delete;
	cout;
	std::cout << endl << "  -------------------------------" << endl;

	controller->deleteShowingInfo(num_for_delete);



}
void AdminProgram::showShowingInfo() {
	std::cout << "  ------------------- �� ���� --------------------" << endl;
	controller->showShowingInfo();
	std::cout << "  ---------------------------------------------------------" << endl;
}

//�̹���, ���ڿ� ���� ����

void AdminProgram::remove(string a) {
	a.erase(std::remove(a.begin(), a.end(), ' '), a.end());
}




//����, �� �ð� �Է�.
string AdminProgram::remove_starttime(string &a) {
	a.erase(std::remove(a.begin(), a.end(), '.'), a.end());
	a.erase(std::remove(a.begin(), a.end(), ':'), a.end());
	return a;
} //��������

string AdminProgram::input_starttime() {
	string starttime;

	cout << "�󿵽ð� 2019�� 12�� 05�� 12��30�� = 2019.12.05.12:30 �������� �Է����ּ���" << endl;
	getline(std::cin, starttime);

	starttime = remove_starttime(starttime);

	cout << starttime << endl;

	return starttime;
}
