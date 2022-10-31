#include <iostream>
#include "AdminProgram.h"


int main() {


	AdminProgram* p = new AdminProgram();
	p->addMovie();
	p->addMovie();
	p->showMovie();

	p->deleteMovie();
	p->showMovie();

	return 0;
}