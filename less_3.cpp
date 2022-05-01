#define _CRT_SECURE_NO_WARNINGS
#include "simulator.h"
#include "configur.h"

//0556707712 מירי 

void main() {
	simulator* s = new simulator();
	std::cout << "good!!\n";
	if (s != NULL) {
		s->begin();
		std::cout << "very good!!\n";
		s->printAllCmera();
		delete(s);
	}
}