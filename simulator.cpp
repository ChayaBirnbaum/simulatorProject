#include "simulator.h"

simulator::simulator() {
	config = new configur();
	arrCamera = (camera**)malloc(config->getNumOfCamera() * sizeof(camera*));
	if (arrCamera == NULL)
	{
		std::cout << "alocation failed";
		exit(1);
	}
	for (int i = 0; i < config->getNumOfCamera(); i++) {
		arrCamera[i] = new camera('a' + i);
	}
}

void simulator::begin() {
	int a = 0;
	std::thread threades_camera[MAX_CAMERA];
	std::thread threades_sendToServer[MAX_CAMERA];
	for (int i = 0; i < config->getNumOfCamera(); i++)
	{
		//(*(arrCamera[i])).run();
		threades_camera[i] = std::thread(&camera::run, *(arrCamera[i]));
		threades_sendToServer[i] = std::thread(&camera::sendToServer, *(arrCamera[i]));
	}
	char x;
	std::cout << "Press any key to stop\n";
	std::cin >> x;
	for (int i = 0; i < config->getNumOfCamera(); i++)
	{
		(*(arrCamera[i])).stop();
		threades_camera[i].detach();//.detach();//join?
		threades_sendToServer[i].detach();
	}
}

void simulator::printAllCmera() {
	for (int i = 0; i < config->getNumOfCamera(); i++) {
		this->arrCamera[i]->printDetailes();
	}
}

simulator::~simulator() {
	delete(config);
	for (int i = 0; i < config->getNumOfCamera(); i++) {
		if (arrCamera[i] != NULL)
			delete(arrCamera[i]);
	}
	free(arrCamera);
}