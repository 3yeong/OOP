#include "Controller.h"
#include "Data.h"
#include <iostream>
#include <fstream>
#include <vector>

/*
//추가 구현 해야 할 부분 :
	1) validation
		-addMovie : 영화 제목이 동일 할 경우 추가 한함
		
*/

Controller::Controller()
{
	
	data = new Data();
	
	FILE *fp;
	
	fopen_s(&fp, "data.bin", "rb");		// 파일을 읽기/바이너리 모드(rb)로 열기
	if (fp) {
		fread(data, sizeof(Data), 1, fp);			// 파일의 내용을 읽어서 클래스 변수에 저장
		fclose(fp);									// 파일 포인터 닫기

		int i;
		for (i = 0; i < 20; i++) {
			Movie movie_ = data->movie_list[i];

			if (movie_.title == "") {
				Data::movie_count = i;
				break;
			}
		}
		for (i = 0; i < 20; i++) {
			Theater theater_ = data->theater_list[i];

			if (theater_.num_of_theater == NULL) {
				Data::theater_count = i;
				break;
			}
		}
		for (i = 0; i < 20; i++) {
			ShowingInfo showingInfo_ = data->showingInfo_list[i];

			if (showingInfo_.title == "") {
				Data::showingInfo_count = i;
				break;
			}
		}

	}
}


Controller::~Controller()
{
}

//Movie 객체 생성하여 Data에 저장.
void Controller::addMovie(string title, string release_date, string showtime, string old) {
	
	Movie movie_for_add = Movie(title, release_date, showtime, old);
	data->add_Movie(movie_for_add);
	dataWrite(data);
	dataRead();
	
	
	
}
void Controller::showMovieList() {
	for (int i = 0; i < data->movie_count; i++) {
		cout << i << " : " << data->movie_list[i].title << " ," << data->movie_list[i].release_date;
	}
}


void Controller::deleteMovie(string title) {

	for (int i = 0; i < data->movie_count; i++) {
		if (data->movie_list[i].title == title) {
			for (int j = i; j < data->movie_count-1; j++) {
				data->movie_list[j] = data->movie_list[j + 1];
			}
			break;
		}
	}
	data->movie_count--;
	dataWrite(data);
	dataRead();

}






//Theater객체 생성하여 Data에 저장.
void Controller::addTheater(int num_of_theater, int row, int col) {
	Theater theater_for_add = Theater(num_of_theater, row, col);
	data->add_Theater(theater_for_add);
	dataWrite(data);
	dataRead();

}



void Controller::addShowingInfo(string title, int num_of_theater) {

	int row ,col;
	for (int i = 0; i < 20; i++) {
		Theater theater_ = data->theater_list[i];
		if (theater_.num_of_theater == num_of_theater) {
			row = theater_.row;
			col = theater_.col;
		}
	}

	
	ShowingInfo showingInfo_for_add = ShowingInfo(title, num_of_theater);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			showingInfo_for_add.setSeat(i, j, row, col);
		}
	}
	data->add_ShowingInfo(showingInfo_for_add);
	
	dataWrite(data);
	dataRead();

}









void Controller::dataRead() {
	
	FILE *fp;
	
	fopen_s(&fp, "data.bin", "rb");   // 파일을 읽기/바이너리 모드(rb)로 열기
	fread(data, sizeof(Data), 1, fp);         // 파일의 내용을 읽어서 클래스 변수에 저장
	fclose(fp);    // 파일 포인터 닫기
	
}

void Controller::dataWrite(Data* data ) {
	
	Data d = *data;
	FILE *fp;
	fopen_s(&fp, "data.bin", "wb");   // 파일을 쓰기/바이너리 모드(wb)로 열기
	if (fwrite(&d, sizeof(Data), 1, fp));    // 클래스 내용을 파일에 저장
	fclose(fp);    // 파일 포인터 닫기


}