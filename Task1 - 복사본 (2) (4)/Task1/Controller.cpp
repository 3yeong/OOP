#include "Controller.h"
#include "Data.h"
#include <iostream>
#include <fstream>
#include <time.h>

/*
//�߰� ���� �ؾ� �� �κ� :
	1) validation
		-addMovie : ��ȭ ������ ���� �� ��� �߰� ����
		
*/

Controller::Controller()
{
	
	data = new Data();
	
	FILE *fp;
	
	fopen_s(&fp, "data.bin", "rb");		// ������ �б�/���̳ʸ� ���(rb)�� ����
	if (fp) {
		fread(data, sizeof(Data), 1, fp);			// ������ ������ �о Ŭ���� ������ ����
		fclose(fp);									// ���� ������ �ݱ�
	}


	else {
		data->movie_count = 0;
		data->theater_count = 0;
		data->showingInfo_count = 0;
	}



	

	userdata = new UserData();


	fopen_s(&fp, "userdata.bin", "rb");		// ������ �б�/���̳ʸ� ���(rb)�� ����
	if (fp) {
		fread(userdata, sizeof(UserData), 1, fp);			// ������ ������ �о Ŭ���� ������ ����
		fclose(fp);									// ���� ������ �ݱ�


	}
	else {
		userdata->user_count = 0;
		userdata->userUnknown_count = 0;
		
	}

	
	dataWrite(data);
	userdataWrite(userdata);
}


Controller::~Controller()
{
}









bool Controller::addMovie(string title, string release_date, string showtime, int age) {
	
	Movie movie_for_add = Movie(title, release_date, showtime, age);
	bool check = data->add_Movie(movie_for_add);
	if (!check) {
		dataWrite(data);
		dataRead();
	}
	return check;
	
}
void Controller::showMovieList() {
	
	dataRead();
	for (int i = 0; i < data->movie_count; i++) {
		cout <<"<"<< i+1 << ">" <<" "<< data->movie_list[i].title << endl;
	}
}

//ȿ��(7��)
bool Controller::deleteMovie(string title) {
	bool check_title = false;

	for (int i = 0; i < data->movie_count; i++) {
		if (data->movie_list[i].title == title) {
			check_title = true;
			break;
		}

	}

	if (check_title) {
		data->delete_Movie(title);
		data->delete_ShowingInfo(title);
		dataWrite(data);
		dataRead();
	}

	return check_title;
}









//Theater��ü �����Ͽ� Data�� ����.
// ȿ��(5��)
bool Controller::addTheater(int num_of_theater, int row, int col) {
	bool check_theater = false;
	for (int i = 0; i < data->theater_count; i++) {
		if (data->theater_list[i].num_of_theater == num_of_theater) {
			check_theater = true;
		}
	}
	if (!check_theater) {
		Theater theater_for_add = Theater(num_of_theater, row, col);

		data->add_Theater(theater_for_add);
		dataWrite(data);
		dataRead();
	}
	return check_theater;
}
void Controller::deleteTheater(int num_of_theater) {

	data->delete_Theater(num_of_theater);
	dataWrite(data);
	dataRead();

}
void Controller::showTheater() {
	
	dataRead();
	for (int i = 0; i < data->theater_count; i++) {
		cout << "<" << data->theater_list[i].num_of_theater << "��>" << endl;
		cout << "�¼� : " << data->theater_list[i].row << "��" << data->theater_list[i].col << "��" << endl;
	}
}











// ȿ��(4��)
int Controller::addShowingInfo(string title, int num_of_theater, string starttime) {
	bool check_title = false;
	bool check_theater = false;
	int result = 0;// 0�̸� �������� 1�̸� ������ �����ʰ� 2�̸� �󿵰��� �����ʰ� 3�̸� �Ѵ� �����ʴ�
	for (int i = 0; i < data->movie_count; i++) {
		if (data->movie_list[i].title == title) {
			check_title = true;
			break;
		}

	}

	for (int i = 0; i < data->theater_count; i++) {
		if (data->theater_list[i].num_of_theater == num_of_theater) {
			check_theater = true;
			break;
		}
	}

	if (check_title&&check_theater) {
		int row, col;
		for (int i = 0; i < 20; i++) {
			Theater theater_ = data->theater_list[i];
			if (theater_.num_of_theater == num_of_theater) {
				row = theater_.row;
				col = theater_.col;
			}
		}


		ShowingInfo showingInfo_for_add = ShowingInfo(title, num_of_theater, starttime);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				showingInfo_for_add.setSeat(i, j, row, col);
			}
		}

		data->add_ShowingInfo(showingInfo_for_add);

		dataWrite(data);
		dataRead();

	}
	else if (!check_title && !check_theater)
		result = 3;
	else if (!check_title && check_theater)
		result = 1;
	else if (check_title && !check_theater)
		result = 2;
	return result;
}
void Controller::deleteShowingInfo(string title, int num_of_theeater, string starttime) {

	data->delete_ShowingInfo(title, num_of_theeater, starttime);
	dataWrite(data);
	dataRead();

}

void Controller::deleteShowingInfoAuto(string starttime) {

	
	for (int i = 0; i < data->showingInfo_count; i++) {
		if (stoll(data->showingInfo_list[i].starttime) < stoll(starttime)) {
			data->delete_ShowingInfo(data->showingInfo_list[i].title, data->showingInfo_list[i].number_of_theater, data->showingInfo_list[i].starttime);
		}
	}

}

void Controller::deleteShowingInfo(int num_for_delete) {
	
	data->delete_ShowingInfo(num_for_delete-1);
	dataWrite(data);
	dataRead();
}




void Controller::showShowingInfo() {


	dataRead();

	for (int i = 0; i < data->showingInfo_count; i++) {
		cout << "<" << i + 1 << "��° ������>" << endl << "���� : " << data->showingInfo_list[i].title<< endl << "�󿵰� : " << data->showingInfo_list[i].number_of_theater << endl << "�󿵽��۽ð� : " << data->showingInfo_list[i].starttime<<endl;
		
		Theater theater_ = data->getTheater(data->showingInfo_list[i].number_of_theater);
		
		for (int j = 0; j < theater_.row; j++) {
			
			for (int k = 0; k< theater_.col; k++) {
				cout << "[ " << char(data->showingInfo_list[i].getSeat(j, k, theater_.row, theater_.col).row + 65) << data->showingInfo_list[i].getSeat(j, k, theater_.row, theater_.col).col << " ]";
			}
			cout << endl;
		}


	}

	

}







string Controller::search_ticketNumber(string phone) {

	for (int i = 0; i < userdata->userUnknown_count; i++) {
		if (userdata->userUknown[i].ticket.phoneNumber == phone) {
			return userdata->userUknown[i].ticket.thicketNUmber;
		}
	}

	return "null";
}









void Controller::dataRead() {

	
	
	FILE *fp;
	
	fopen_s(&fp, "data.bin", "rb");   // ������ �б�/���̳ʸ� ���(rb)�� ����
	fread(data, sizeof(Data), 1, fp);         // ������ ������ �о Ŭ���� ������ ����
	fclose(fp);    // ���� ������ �ݱ�
	struct tm datetime;
	time_t timer;
	timer = time(NULL);
	localtime_s(&datetime, &timer);

	char buffer[10];

	sprintf_s(buffer, "%02d", datetime.tm_mon + 1);
	string mon = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_mday);
	string date = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_hour);
	string hour = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_min);
	string min = buffer;

	string t = to_string(datetime.tm_year + 1900) + mon + date + hour + min;

	deleteShowingInfoAuto(t);
	
}

void Controller::dataWrite(Data* data ) {
	


	struct tm datetime;
	time_t timer;
	timer = time(NULL);
	localtime_s(&datetime, &timer);
	
	char buffer[10];

	sprintf_s(buffer, "%02d", datetime.tm_mon + 1);
	string mon = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_mday);
	string date = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_hour);
	string hour = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_min);
	string min = buffer;

	string t = to_string(datetime.tm_year+ 1900) + mon + date + hour + min;
	
	

	deleteShowingInfoAuto(t);
	

	Data d = *data;
	FILE *fp;
	fopen_s(&fp, "data.bin", "wb");   // ������ ����/���̳ʸ� ���(wb)�� ����
	if (fwrite(&d, sizeof(Data), 1, fp));    // Ŭ���� ������ ���Ͽ� ����
	fclose(fp);    // ���� ������ �ݱ�


}




Data* Controller::getdata() {
	return this->data;
}

void Controller::userdataRead() {



	FILE *fp;

	fopen_s(&fp, "userdata.bin", "rb");   // ������ �б�/���̳ʸ� ���(rb)�� ����
	fread(userdata, sizeof(UserData), 1, fp);         // ������ ������ �о Ŭ���� ������ ����
	fclose(fp);    // ���� ������ �ݱ�
	struct tm datetime;
	time_t timer;
	timer = time(NULL);
	localtime_s(&datetime, &timer);

	char buffer[10];

	sprintf_s(buffer, "%02d", datetime.tm_mon + 1);
	string mon = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_mday);
	string date = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_hour);
	string hour = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_min);
	string min = buffer;

	string t = to_string(datetime.tm_year + 1900) + mon + date + hour + min;

}

void Controller::userdataWrite(UserData* userdata) {



	struct tm datetime;
	time_t timer;
	timer = time(NULL);
	localtime_s(&datetime, &timer);

	char buffer[10];

	sprintf_s(buffer, "%02d", datetime.tm_mon + 1);
	string mon = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_mday);
	string date = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_hour);
	string hour = buffer;

	sprintf_s(buffer, "%02d", datetime.tm_min);
	string min = buffer;

	string t = to_string(datetime.tm_year + 1900) + mon + date + hour + min;


	UserData d = *userdata;
	FILE *fp;
	fopen_s(&fp, "userdata.bin", "wb");   // ������ ����/���̳ʸ� ���(wb)�� ����
	if (fwrite(&d, sizeof(UserData), 1, fp));    // Ŭ���� ������ ���Ͽ� ����
	fclose(fp);    // ���� ������ �ݱ�


}





//



//ȿ��(6��)
bool Controller::sign_in(string name, string ph, string id, string pw) {
	bool check_id = true;
	for (int i = 0; i < userdata->user_count; i++) {
		if (userdata->user[i].id == id) {
			check_id = false;
		}
	}
	if (check_id) {
		userdata->user[userdata->user_count] = User(name, ph, id, pw);
		userdata->user_count++;
		userdataWrite(userdata);
		userdataRead();
	}


	return check_id;
}

bool Controller::log_in(string id, string pw) {

	for (int i = 0; i < userdata->user_count; i++) {
		if (userdata->user[i].id == id) {
			if (userdata->user[i].password == pw) {
				this->currentUser = &userdata->user[i];
				return true;
			}
			else {
				return false;
			}
		}
	}

	return false;

}


// ȿ��(<��ȣ>�ð����� ���̰� ����)
bool Controller::showShowingInfo(string title) {

	dataWrite(data);
	dataRead();
	bool check = false;
	for (int i = 0; i < data->showingInfo_count; i++) {
		if (data->showingInfo_list[i].title == title) {
			cout << "  <" << i + 1 << ">" << "  �� ���� �ð� : " << data->showingInfo_list[i].starttime << endl;
			check = true;
		}
	}
	return check;

}
//ȿ��(8��)
bool Controller::screen_num(string title, int num) {
	dataWrite(data);
	dataRead();
	bool check = false;
	for (int i = 0; i < data->showingInfo_count; i++) {
		if (data->showingInfo_list[i].title == title) {
			if ((i + 1) == num) {
				check = true;
			}
		}
	}
	return check;
}
void Controller::showSeat(int i) {

	ShowingInfo showing_info = data->showingInfo_list[i];


	Theater theater_ = data->getTheater(data->showingInfo_list[i].number_of_theater);

	for (int j = 0; j < theater_.row; j++) {

		for (int k = 0; k < theater_.col; k++) {
			if (data->showingInfo_list[i].getSeat(j, k, theater_.row, theater_.col).isbooked == 0) {
				cout << "[ " << char(data->showingInfo_list[i].getSeat(j, k, theater_.row, theater_.col).row + 65) << data->showingInfo_list[i].getSeat(j, k, theater_.row, theater_.col).col << " ]";
				
			}
			else {
				cout << "[ " << "  " << " ]";
			}
		}
		cout << endl;
	}
}


Ticket Controller::makeTicket(int kid, int adult, int k, int n,  string *seat) {


	
	dataRead();
	
	userdataRead();
	
	Ticket ticket = Ticket();
	Theater theater_ = data->getTheater(data->showingInfo_list[k].number_of_theater);
	
	for (int i = 0; i < n; i++) {
		
		int r = (int)seat[i].at(0) - 65;
		int l = seat[i].at(1) - 48;

	
		
		r = r + 1;

		int col = theater_.col;

		int num = (r - 1)*col + l;

		
		
		data->showingInfo_list[k].seat[num].isSelected = 1;

		ticket.seat[i] = seat[i];
		ticket.total_num = n;
		ticket.adult = adult;
		ticket.child = kid;
		ticket.numOfShowinginfo = k;

		struct tm datetime;
		time_t timer;
		timer = time(NULL);
		localtime_s(&datetime, &timer);

		char buffer[10];

		sprintf_s(buffer, "%02d", datetime.tm_mon + 1);
		string mon = buffer;

		sprintf_s(buffer, "%02d", datetime.tm_mday);
		string date = buffer;

		sprintf_s(buffer, "%02d", datetime.tm_hour);
		string hour = buffer;

		sprintf_s(buffer, "%02d", datetime.tm_min);
		string min = buffer;

		sprintf_s(buffer, "%02d", datetime.tm_sec);
		string sec = buffer;

		string t = to_string(datetime.tm_year + 1900) + mon + date + hour + min + sec;

		ticket.thicketNUmber = t;


		dataWrite(data);
		dataRead();

	}

	return ticket;



}


bool Controller::isSelected(int k, int n, string *seat) {
	
	dataRead();
	userdataWrite(userdata);
	userdataRead();

	Theater theater_ = data->getTheater(data->showingInfo_list[k].number_of_theater);

	for (int i = 0; i < n; i++) {

		int r = (int)seat[i].at(0) - 65;
		int l = seat[i].at(1) - 48;



		r = r + 1;

		int col = theater_.col;

		int num = (r - 1)*col + l;



		if (data->showingInfo_list[k].seat[num].isSelected == 1) {
			return true;
		}

		


		
	}
	return false;

}
bool Controller::isBooked(int k, int n, string *seat) {
	
	dataRead();
	
	userdataRead();

	Theater theater_ = data->getTheater(data->showingInfo_list[k].number_of_theater);

	for (int i = 0; i < n; i++) {

		int r = (int)seat[i].at(0) - 65;
		int l = seat[i].at(1) - 48;



		r = r + 1;

		int col = theater_.col;

		int num = (r - 1)*col + l;



		if (data->showingInfo_list[k].seat[num].isbooked == 1) {

			return true;
		}

	}
	return false;

}

void Controller::payticket(int method, int amount, Ticket ticket) {

	if (method == 1) {
		ticket.payment.method_of_payment = "card";
	}
	else if (method == 2) {
		ticket.payment.method_of_payment = "cash";
	}

	ticket.payment.amount_of_payment = amount;
	ticket.payment.usedPoint = 0;

	this->currentUser->ticket[this->currentUser->ticket_count] = ticket;
	this->currentUser->ticket_count++;
	
	this->userdataWrite(this->userdata);
	this->userdataRead();

}
void Controller::payticketForUnknown(int method, int amount, Ticket ticket) {

	if (method == 1) {
		ticket.payment.method_of_payment = "card";
	}
	else if (method == 2) {
		ticket.payment.method_of_payment = "cash";
	}

	ticket.payment.amount_of_payment = amount;
	ticket.payment.usedPoint = 0;

	UserUnknown userUnknown = UserUnknown();
	userUnknown.ticket = ticket;
	cout << userdata->userUnknown_count;
	userdata->userUknown[userdata->userUnknown_count] = userUnknown;
	userdata->userUnknown_count++;
	this->userdataWrite(this->userdata);
	this->userdataRead();
}

void Controller::bookTicket(int kid, int adult, int k, int n, string *seat) {
	Theater theater_ = data->getTheater(data->showingInfo_list[k].number_of_theater);

	for (int i = 0; i < n; i++) {

		int r = (int)seat[i].at(0) - 65;
		int l = seat[i].at(1) - 48;



		r = r + 1;

		int col = theater_.col;

		int num = (r - 1)*col + l;



		data->showingInfo_list[k].seat[num].isbooked = 1;




		dataWrite(data);
		dataRead();

	}
}


Ticket Controller::search_ticket(string ticketNumber) {

	for (int i = 0; i < userdata->userUnknown_count; i++) {
		if (userdata->userUknown[i].ticket.thicketNUmber == ticketNumber) {
			return userdata->userUknown[i].ticket;
		}
	}
	Ticket t = Ticket();
	t.thicketNUmber = "";
	return t;

}

bool Controller::return_ticket(string ticketNumber) {
	for (int i = 0; i < userdata->userUnknown_count; i++) {

		if (userdata->userUknown[i].ticket.thicketNUmber == ticketNumber) {
			
			
			int k = userdata->userUknown[i].ticket.numOfShowinginfo;
			Theater theater_ = data->getTheater(data->showingInfo_list[k].number_of_theater);
			int n = userdata->userUknown[i].ticket.total_num;
			string *seat = userdata->userUknown[i].ticket.seat;

			for (int j = 0; j< n; j++) {

				int r = (int)seat[j].at(0) - 65;
				int l = seat[j].at(1) - 48;



				r = r + 1;

				int col = theater_.col;

				int num = (r - 1)*col + l;



				data->showingInfo_list[k].seat[num].isbooked = 0;
				data->showingInfo_list[k].seat[num].isSelected = 0;



				dataWrite(data);
				dataRead();
				userdataWrite(userdata);
				userdataRead();
			}
			for (int p = i; p < userdata->userUnknown_count-1; p++) {
				userdata->userUknown[p] = userdata->userUknown[p + 1];
			}
			userdata->userUnknown_count--;
			dataWrite(data);
			dataRead();
			userdataWrite(userdata);
			userdataRead();
			break;

		}


	}
	return true;
}

bool Controller::return_ticket(int ticketNumber) {



	int k = currentUser->ticket[ticketNumber].numOfShowinginfo;
	Theater theater_ = data->getTheater(data->showingInfo_list[k].number_of_theater);
	int n = currentUser->ticket[ticketNumber].total_num;
	string *seat = currentUser->ticket[ticketNumber].seat;

	for (int j = 0; j < n; j++) {

		int r = (int)seat[j].at(0) - 65;
		int l = seat[j].at(1) - 48;



		r = r + 1;

		int col = theater_.col;

		int num = (r - 1)*col + l;



		data->showingInfo_list[k].seat[num].isbooked = 0;
		data->showingInfo_list[k].seat[num].isSelected = 0;



		dataWrite(data);
		dataRead();
		userdataWrite(userdata);
		userdataRead();
	}
	for (int p = ticketNumber; p < currentUser->ticket_count - 1; p++) {
		currentUser->ticket[p] = currentUser->ticket[p + 1];
	}
	currentUser->ticket_count--;
	dataWrite(data);
	dataRead();
	userdataWrite(userdata);
	userdataRead();
	return true;
}

int Controller::ageCheck(string title) {
	for (int i = 0; i < data->movie_count; i++) {
		if (data->movie_list[i].title == title) {
			return data->movie_list[i].age;
		}
	}
	return NULL;
}