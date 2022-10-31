#include "Controller.h"
#include "Data.h"
#include <iostream>
#include <fstream>
#include <vector>

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

//Movie ��ü �����Ͽ� Data�� ����.
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






//Theater��ü �����Ͽ� Data�� ����.
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
	
	fopen_s(&fp, "data.bin", "rb");   // ������ �б�/���̳ʸ� ���(rb)�� ����
	fread(data, sizeof(Data), 1, fp);         // ������ ������ �о Ŭ���� ������ ����
	fclose(fp);    // ���� ������ �ݱ�
	
}

void Controller::dataWrite(Data* data ) {
	
	Data d = *data;
	FILE *fp;
	fopen_s(&fp, "data.bin", "wb");   // ������ ����/���̳ʸ� ���(wb)�� ����
	if (fwrite(&d, sizeof(Data), 1, fp));    // Ŭ���� ������ ���Ͽ� ����
	fclose(fp);    // ���� ������ �ݱ�


}