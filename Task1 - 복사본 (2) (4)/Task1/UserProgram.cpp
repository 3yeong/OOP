#include "UserProgram.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS


//회원가입
//로그인
//티켓예매 (로그인, 비회원 택 1) -> 영화선택 -> 시간선택 -> 예매할 좌석 인원 선택 (어른 1 아이1 ...) -> 좌석 선택 -> 결제방식 선택 -> 포인트 사용여부체크 (얼마 사용할 건지) -> 결제 금액 출력 ->예매 정보 출력 후 초기화면으로
//예매 취소 (취소할 티켓 선택) ->포인트 복구 후 초기화면.
//예매정보 보기 (로그인, 비회원 택 1) -> 비회원의 경우는 전화번호 입력으로 대체.



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
			islogin = "로그인";
			sign_up = "  11. 회원가입";
			info = "(6)예매 번호 찾기";

		}
		else {
			islogin = "로그아웃";
			sign_up = "";
			info = "(5)회원정보";
		}

		int menu;
		cout << endl << endl << endl << endl;
		cout << "*********** 영화 예매 프로그램 ************ " << endl << endl;
		cout << "  1. " << islogin << endl << "  2. 영화 예매" << endl << "  3. 예매 취소" << endl << "  4. 예매 정보	" << info << endl << "  10. 종료 " << endl << sign_up << endl;



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
	cout << "전화번호 : ";
	cout;
	string phone;

	phone = input_phoneNum();
	cout << controller->search_ticketNumber(phone);
}
void UserProgram::cancel() {
	if (controller->currentUser == NULL) {



		string ticketnum;
		cout << "취소할 티켓번호 입력 : ";
		cout;

		cin >> ticketnum;

		controller->return_ticket(ticketnum);

	}
	else {
		show_ticket();
		cout << "취소할 티켓 선택 : ";
		cout;
		int n;
		cin >> n;

		controller->return_ticket(n);
	}
}

void UserProgram::showUserInfo() {

	cout << "이름 : " << controller->currentUser->name << endl;
	cout << "전화번호" << controller->currentUser->phoneNumber << endl;
	cout << "가용 포인트" << controller->currentUser->point << endl;

}

void UserProgram::sign_up() {
	string name;
	string phoneNumber;
	string id;
	string password;

	cout << "  ------- 회원가입 -------" << endl;
	cout << "  이름 : ";
	cin >> name;
	cout;
	cout << "  전화번호 : ";
	phoneNumber = input_phoneNum();
	cout;
	cout << "  id : ";
	cin >> id;
	cout;
	password = input_password();
	password = encrypt(password, id);
	cout;


	//효인(6번)
	if (controller->sign_in(name, phoneNumber, id, password)) {
		cout << "  가입되었습니다." << endl;
	}
	else {
		cout << "  동일한 id가 있습니다. 다시 입력해주세요!" << endl;
	}
	cout << "  ---------------------" << endl;

}


bool UserProgram::log_inout() {
	char n = 'N';
	while (n == 'N') {


		if (controller->currentUser == NULL) {
			string id;
			string pw;

			cout << "  ------- 로그인 -------" << endl;
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
				cout << "  아이디 또는 비밀번호가 틀립니다." << endl << "  메인메뉴로(Y / N) ";
				cin >> n;
				cout;
			}
			else {
				break;
			}
		}
		else {
			cout << "  ------ 로그아웃 ------" << endl;
			controller->currentUser = NULL;
			cout << "  로그아웃 되었습니다." << endl;
			break;
		}

	}
	cout << "  ----------------------";
	return 0;
}



void UserProgram::ticketing() {



	cout << "  ------ 영화 예매 ------" << endl;

	controller->showMovieList();
	string title;
	cout << endl;

	cout << "  예매할 영화 제목: ";
	cin >> title;
	cout << endl;

	bool check = controller->showShowingInfo(title);
	int age = controller->ageCheck(title);



	if (!check) {
		cout << "  해당 영화의 상영 정보가 없습니다!! " << endl;
	}
	else {
		int showingInfoNumber;

		cout << "  예매할 상영번호 선택 : ";
		cin >> showingInfoNumber;
		//효인(8번)
		bool check2 = controller->screen_num(title, showingInfoNumber);
		cout << endl;
		if (!check2) {
			cout << "  해당 상영 번호가 없습니다. 다시 입력해주세요! " << endl;
		}
		else {
			showingInfoNumber--;

			int numOfAdult = 0;
			int numOfChild = 0;

			cout << "  인원 선택";
			cout;
			cout << "  성인(11000) : ";
			cin >> numOfAdult;
			cout;
			if (age < 19) {
				cout << "청소년(8000원) : ";

				cin >> numOfChild;
				cout << endl;
			}

			int numOfPeople = numOfChild + numOfAdult;

			controller->showSeat(showingInfoNumber);


			string* s = seat(numOfPeople);

			while (true) {
				if (controller->isBooked(showingInfoNumber, numOfPeople, s)) {
					cout << "  이미 예매된 좌석입니다.";
					cout << endl;
					controller->showSeat(showingInfoNumber);

					s = seat(numOfPeople);
				}
				else {
					if (controller->isSelected(showingInfoNumber, numOfPeople, s)) {
						cout << "  이미 선택된 좌석입니다.";
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
				cout << "휴대폰 번호 입력 : ";
				cout;
				phone = input_phoneNum();

				t.phoneNumber = phone;

				int method_payment;

				cout << "  결제 방법을 선택하세요. 1)카드 2)현금";
				cin >> method_payment;
				int payment = 8000 * numOfChild + 11000 * numOfAdult;

				cout << "  결제금액은 " << payment << "원 입니다." << endl;
				controller->payticketForUnknown(method_payment, payment, t);

				controller->bookTicket(numOfChild, numOfAdult, showingInfoNumber, numOfPeople, s);

				cout << "  결제 완료" << endl;

				cout << "  예매번호 : " << t.thicketNUmber << endl;





			}
			else {

				int method_payment;

				cout << "  결제 방법을 선택하세요. 1)카드 2)현금";
				cin >> method_payment;
				int payment = 8000 * numOfChild + 11000 * numOfAdult;

				cout << "  결제금액은 " << payment << "원 입니다." << endl;
				controller->payticket(method_payment, payment, t);

				controller->bookTicket(numOfChild, numOfAdult, showingInfoNumber, numOfPeople, s);

				cout << "  결제 완료" << endl;

				cout << "  예매번호 : " << t.thicketNUmber << endl;

			}
		}

	}
	cout << "  -----------------------" << endl;
}



//세영. 인원수에 맞게 
string* UserProgram::seat(int num) {
	std::string * p = new std::string[num];//return 할 배열
	std::string str_arr[1000];
	int k = 1;
	int n = 0;
	while (k == 1)
	{
		int cheak = 0;
		int str_cnt = 0;//개수 체크

		std::string seat_in;
		char *str_buff = new char[1000];

		std::cout << "자리를 입력해 주세요." << std::endl;
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
			std::cout << "인원 수와 좌석 선택 수가 다릅니다." << std::endl;
			std::cout << "다시 입력해주세요.\n" << std::endl;
			k = 1;
		}
		else {
			for (int j = 0; j < num; j++) {
				char a[3];
				strcpy(a, str_arr[j].substr(0, 2).c_str());
				if (!isalpha(a[0])) {
					std::cout << "입력한 값이 형식에 맞지 않습니다." << std::endl;
					std::cout << "다시 입력해주세요.\n" << std::endl;
					cheak = 1;
					break;
				}
				else if (!isdigit(a[1])) {
					std::cout << "입력한 값이 형식에 맞지 않습니다." << std::endl;
					std::cout << "다시 입력해주세요.\n" << std::endl;
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




	//세영, 티켓내용출력 추가
	void UserProgram::show_ticket() {

		string ticketNum;

		if (controller->currentUser == NULL) {
			cout << "예매번호 : ";
			cout;
			cin >> ticketNum;


			Ticket t = controller->search_ticket(ticketNum);
			if (t.thicketNUmber != "") {
				int a = t.numOfShowinginfo;
				cout << controller->data->movie_list[a].title << endl;
				cout << controller->data->showingInfo_list[a].number_of_theater << endl;
				cout << "상영시간 : " << controller->data->showingInfo_list[a].starttime << endl;
				cout << "좌석 : ";
				for (int i = 0; i < t.total_num; i++) {
					cout << t.seat[i] << " ";
				}
				cout << endl;
				cout << "-------------------------------" << endl;
			}
			else {
				cout << "존재하지 않는 티켓 번호 입니다." << endl;
			}
		}
		else {
			for (int i = 0; i < controller->currentUser->ticket_count; i++) {
				cout << controller->data->movie_list[i].title << endl;
				cout << "상영시간 : " << controller->data->showingInfo_list[i].starttime << endl;
				cout << "좌석 : ";
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


	//이범수, 비밀번호 암호화, 복호화.
	std::string UserProgram::encrypt(std::string password, std::string key)  //암호화
	{
		std::string tmp(key);
		while (key.size() < password.size())
			key += tmp;

		for (std::string::size_type i = 0; i < password.size(); ++i)
			password[i] ^= key[i];
		return password;
	}
	std::string UserProgram::decrypt(std::string password, std::string key)  //복호화
	{
		return encrypt(password, key);
	}


	//세영, 전화번호 입력.
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
				std::cout << "  전화번호는 11자리 입니다. \n 다시 입력해주세요 :" << std::endl;
				k = 1;
			}
			else {
				k = 0;
			}
		}

		return a;
	}