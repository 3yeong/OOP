#include "UserProgram.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS


//ȸ������
//�α���
//Ƽ�Ͽ��� (�α���, ��ȸ�� �� 1) -> ��ȭ���� -> �ð����� -> ������ �¼� �ο� ���� (� 1 ����1 ...) -> �¼� ���� -> ������� ���� -> ����Ʈ ��뿩��üũ (�� ����� ����) -> ���� �ݾ� ��� ->���� ���� ��� �� �ʱ�ȭ������
//���� ��� (����� Ƽ�� ����) ->����Ʈ ���� �� �ʱ�ȭ��.
//�������� ���� (�α���, ��ȸ�� �� 1) -> ��ȸ���� ���� ��ȭ��ȣ �Է����� ��ü.



UserProgram::UserProgram()
{

	this->controller = new Controller();

}


UserProgram::~UserProgram()
{
}

bool UserProgram::user() {

	while (true) {

		string islogin;
		string sign_up;
		string info;

		if (controller->currentUser == NULL) {
			islogin = "�α���";
			sign_up = "  11. ȸ������";
			info = "(6)���� ��ȣ ã��";

		}
		else {
			islogin = "�α׾ƿ�";
			sign_up = "";
			info = "(5)ȸ������";
		}

		int menu;
		cout << endl << endl << endl << endl;
		cout << "*********** ��ȭ ���� ���α׷� ************ " << endl << endl;
		cout << "  1. " << islogin << endl << "  2. ��ȭ ����" << endl << "  3. ���� ���" << endl << "  4. ���� ����	" << info << endl << "  10. ���� " << endl << sign_up << endl;



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
			if (log_inout()) {
				return 1;
			}
			break;
		case 2:
			ticketing();
			break;
		case 3:
			cancel();
			break;
		case 4:
			show_ticket();
			break;
		case 5:
			showUserInfo();
			break;
		case 6:
			find();
			break;
		case 10:
			exit(1);

		case 11:
			this->sign_up();
			break;
		default:
			break;
		}

	}
	return 0;

}

void UserProgram::find() {
	cout << "��ȭ��ȣ : ";
	cout;
	string phone;

	phone = input_phoneNum();
	cout << controller->search_ticketNumber(phone);
}
void UserProgram::cancel() {
	if (controller->currentUser == NULL) {



		string ticketnum;
		cout << "����� Ƽ�Ϲ�ȣ �Է� : ";
		cout;

		cin >> ticketnum;

		controller->return_ticket(ticketnum);

	}
	else {
		show_ticket();
		cout << "����� Ƽ�� ���� : ";
		cout;
		int n;
		cin >> n;

		controller->return_ticket(n);
	}
}

void UserProgram::showUserInfo() {

	cout << "�̸� : " << controller->currentUser->name << endl;
	cout << "��ȭ��ȣ" << controller->currentUser->phoneNumber << endl;
	cout << "���� ����Ʈ" << controller->currentUser->point << endl;

}

void UserProgram::sign_up() {
	string name;
	string phoneNumber;
	string id;
	string password;

	cout << "  ------- ȸ������ -------" << endl;
	cout << "  �̸� : ";
	cin >> name;
	cout;
	cout << "  ��ȭ��ȣ : ";
	phoneNumber = input_phoneNum();
	cout;
	cout << "  id : ";
	cin >> id;
	cout;
	password = input_password();
	password = encrypt(password, id);
	cout;


	//ȿ��(6��)
	if (controller->sign_in(name, phoneNumber, id, password)) {
		cout << "  ���ԵǾ����ϴ�." << endl;
	}
	else {
		cout << "  ������ id�� �ֽ��ϴ�. �ٽ� �Է����ּ���!" << endl;
	}
	cout << "  ---------------------" << endl;

}


bool UserProgram::log_inout() {
	char n = 'N';
	while (n == 'N') {


		if (controller->currentUser == NULL) {
			string id;
			string pw;

			cout << "  ------- �α��� -------" << endl;
			cout << "  id : ";
			cin >> id;
			cout;


			pw = input_password();
			pw = decrypt(pw, id);
			cout;

			string pw_admin = encrypt("password", "admin");

			if (id == "admin") {
				if (pw == pw_admin) {
					return 1;
				}
			}


			bool b = controller->log_in(id, pw);

			if (!b) {
				cout << "  ���̵� �Ǵ� ��й�ȣ�� Ʋ���ϴ�." << endl << "  ���θ޴���(Y / N) ";
				cin >> n;
				cout;
			}
			else {
				break;
			}
		}
		else {
			cout << "  ------ �α׾ƿ� ------" << endl;
			controller->currentUser = NULL;
			cout << "  �α׾ƿ� �Ǿ����ϴ�." << endl;
			break;
		}

	}
	cout << "  ----------------------";
	return 0;
}



void UserProgram::ticketing() {



	cout << "  ------ ��ȭ ���� ------" << endl;

	controller->showMovieList();
	string title;
	cout << endl;

	cout << "  ������ ��ȭ ����: ";
	cin >> title;
	cout << endl;

	bool check = controller->showShowingInfo(title);
	int age = controller->ageCheck(title);



	if (!check) {
		cout << "  �ش� ��ȭ�� �� ������ �����ϴ�!! " << endl;
	}
	else {
		int showingInfoNumber;

		cout << "  ������ �󿵹�ȣ ���� : ";
		cin >> showingInfoNumber;
		//ȿ��(8��)
		bool check2 = controller->screen_num(title, showingInfoNumber);
		cout << endl;
		if (!check2) {
			cout << "  �ش� �� ��ȣ�� �����ϴ�. �ٽ� �Է����ּ���! " << endl;
		}
		else {
			showingInfoNumber--;

			int numOfAdult = 0;
			int numOfChild = 0;

			cout << "  �ο� ����";
			cout;
			cout << "  ����(11000) : ";
			cin >> numOfAdult;
			cout;
			if (age < 19) {
				cout << "û�ҳ�(8000��) : ";

				cin >> numOfChild;
				cout << endl;
			}

			int numOfPeople = numOfChild + numOfAdult;

			controller->showSeat(showingInfoNumber);


			string* s = seat(numOfPeople);

			while (true) {
				if (controller->isBooked(showingInfoNumber, numOfPeople, s)) {
					cout << "  �̹� ���ŵ� �¼��Դϴ�.";
					cout << endl;
					controller->showSeat(showingInfoNumber);

					s = seat(numOfPeople);
				}
				else {
					if (controller->isSelected(showingInfoNumber, numOfPeople, s)) {
						cout << "  �̹� ���õ� �¼��Դϴ�.";
						cout << endl;
						controller->showSeat(showingInfoNumber);

						s = seat(numOfPeople);
					}
					else {
						break;
					}
				}
			}
			Ticket t = controller->makeTicket(numOfChild, numOfAdult, showingInfoNumber, numOfPeople, s);


			if (controller->currentUser == NULL) {

				string phone;
				cout << "�޴��� ��ȣ �Է� : ";
				cout;
				phone = input_phoneNum();

				t.phoneNumber = phone;

				int method_payment;

				cout << "  ���� ����� �����ϼ���. 1)ī�� 2)����";
				cin >> method_payment;
				int payment = 8000 * numOfChild + 11000 * numOfAdult;

				cout << "  �����ݾ��� " << payment << "�� �Դϴ�." << endl;
				controller->payticketForUnknown(method_payment, payment, t);

				controller->bookTicket(numOfChild, numOfAdult, showingInfoNumber, numOfPeople, s);

				cout << "  ���� �Ϸ�" << endl;

				cout << "  ���Ź�ȣ : " << t.thicketNUmber << endl;





			}
			else {

				int method_payment;

				cout << "  ���� ����� �����ϼ���. 1)ī�� 2)����";
				cin >> method_payment;
				int payment = 8000 * numOfChild + 11000 * numOfAdult;

				cout << "  �����ݾ��� " << payment << "�� �Դϴ�." << endl;
				controller->payticket(method_payment, payment, t);

				controller->bookTicket(numOfChild, numOfAdult, showingInfoNumber, numOfPeople, s);

				cout << "  ���� �Ϸ�" << endl;

				cout << "  ���Ź�ȣ : " << t.thicketNUmber << endl;

			}
		}

	}
	cout << "  -----------------------" << endl;
}



//����. �ο����� �°� 
string* UserProgram::seat(int num) {
	std::string * p = new std::string[num];//return �� �迭
	std::string str_arr[1000];
	int k = 1;
	int n = 0;
	while (k == 1)
	{
		int cheak = 0;
		int str_cnt = 0;//���� üũ

		std::string seat_in;
		char *str_buff = new char[1000];

		std::cout << "�ڸ��� �Է��� �ּ���." << std::endl;
		if (n == 0) {
			getchar();
			n++;
		}
		getline(std::cin, seat_in);
		strcpy(str_buff, seat_in.c_str());
		char *tok = strtok(str_buff, " ");
		while (tok != nullptr) {
			str_arr[str_cnt++] = std::string(tok);
			tok = strtok(nullptr, " ");
		}

		if ((str_cnt) != num) {
			std::cout << "�ο� ���� �¼� ���� ���� �ٸ��ϴ�." << std::endl;
			std::cout << "�ٽ� �Է����ּ���.\n" << std::endl;
			k = 1;
		}
		else {
			for (int j = 0; j < num; j++) {
				char a[3];
				strcpy(a, str_arr[j].substr(0, 2).c_str());
				if (!isalpha(a[0])) {
					std::cout << "�Է��� ���� ���Ŀ� ���� �ʽ��ϴ�." << std::endl;
					std::cout << "�ٽ� �Է����ּ���.\n" << std::endl;
					cheak = 1;
					break;
				}
				else if (!isdigit(a[1])) {
					std::cout << "�Է��� ���� ���Ŀ� ���� �ʽ��ϴ�." << std::endl;
					std::cout << "�ٽ� �Է����ּ���.\n" << std::endl;
					cheak = 1;
					break;
				}
			}
			if (cheak == 0) {
				k = 0;
			}
		}
	}
	for (int i = 0; i < num; i++) {
		p[i] = str_arr[i];
	}
	return p;
}




	//����, Ƽ�ϳ������ �߰�
	void UserProgram::show_ticket() {

		string ticketNum;

		if (controller->currentUser == NULL) {
			cout << "���Ź�ȣ : ";
			cout;
			cin >> ticketNum;


			Ticket t = controller->search_ticket(ticketNum);
			if (t.thicketNUmber != "") {
				int a = t.numOfShowinginfo;
				cout << controller->data->movie_list[a].title << endl;
				cout << controller->data->showingInfo_list[a].number_of_theater << endl;
				cout << "�󿵽ð� : " << controller->data->showingInfo_list[a].starttime << endl;
				cout << "�¼� : ";
				for (int i = 0; i < t.total_num; i++) {
					cout << t.seat[i] << " ";
				}
				cout << endl;
				cout << "-------------------------------" << endl;
			}
			else {
				cout << "�������� �ʴ� Ƽ�� ��ȣ �Դϴ�." << endl;
			}
		}
		else {
			for (int i = 0; i < controller->currentUser->ticket_count; i++) {
				cout << controller->data->movie_list[i].title << endl;
				cout << "�󿵽ð� : " << controller->data->showingInfo_list[i].starttime << endl;
				cout << "�¼� : ";
				for (int j = 0; j < controller->currentUser->ticket->total_num; j++) {

					cout << controller->currentUser->ticket[i].seat[j] << " ";
				}
				cout << endl;
				cout << "-------------------------------" << endl;
			}
		}
	}

	string UserProgram::input_password() {
		char answer[100];
		int buffer = 0;
		int i = 0;
		printf("password : ");
		for (i = 0; buffer != 13; i++) {
			answer[i] = _getch();
			if (answer[i] == '\0') {
				i--;
				continue;
			}
			_putch('*');
			buffer = (int)answer[i];
		}
		answer[i - 1] = '\0';
		string pw(answer);
		return pw;
	}


	//�̹���, ��й�ȣ ��ȣȭ, ��ȣȭ.
	std::string UserProgram::encrypt(std::string password, std::string key)  //��ȣȭ
	{
		std::string tmp(key);
		while (key.size() < password.size())
			key += tmp;

		for (std::string::size_type i = 0; i < password.size(); ++i)
			password[i] ^= key[i];
		return password;
	}
	std::string UserProgram::decrypt(std::string password, std::string key)  //��ȣȭ
	{
		return encrypt(password, key);
	}


	//����, ��ȭ��ȣ �Է�.
	string UserProgram::input_phoneNum() {
		int k = 1;
		string a;
		int c = 0;
		while (k == 1) {

			if (c == 0) {
				getchar();
				getline(cin, a);
				c++;
			}
			else {
				getline(cin, a);
			}
			if (a.length() != 11) {
				std::cout << "  ��ȭ��ȣ�� 11�ڸ� �Դϴ�. \n �ٽ� �Է����ּ��� :" << std::endl;
				k = 1;
			}
			else {
				k = 0;
			}
		}

		return a;
	}