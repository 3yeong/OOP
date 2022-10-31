#include <iostream>
#include "AdminProgram.h"
#include "UserProgram.h"


int main() {


	
	while (true) {
		UserProgram *p2 = new UserProgram();
		p2->user();
		p2->~UserProgram();

		AdminProgram* p = new AdminProgram();
		p->admin();
		p->~AdminProgram();
	}
	return 0;

}