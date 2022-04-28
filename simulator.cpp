#include "simulator.h"

simulator::simulator() {
	for (int i = 0; i < len_arrCamera; i++) {
		arrCamera[i] = new camera('a' + i);
	}
}

void simulator::begin() {
	int a = 0;
	std::thread threades[len_arrCamera];
	for (int i = 0; i < len_arrCamera; i++)
	{
		//(*(arrCamera[i])).run();
		threades[i] = std::thread(&camera::run, (*(arrCamera[i])));
	}
	char x;
	std::cout << "Press any key to stop\n";
	std::cin >> x;
	for (int i = 0; i < len_arrCamera; i++)
	{
		(*(arrCamera[i])).stop();
		threades[i].join();//.detach();//join?
	}
}

void simulator::printAllCmera() {
	for (int i = 0; i < len_arrCamera; i++) {
		this->arrCamera[i]->printDetailes();
	}
}

simulator::~simulator() {
	for (int i = 0; i < len_arrCamera; i++) {
		if (arrCamera[i] != NULL)
			delete(arrCamera[i]);
	}
}