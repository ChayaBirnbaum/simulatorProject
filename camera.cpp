#include "camera.h"

camera::camera(char id) {
	idCamera = id;
}

void camera::generate() {
	int type = rand() % 2 + 1;
	baseMessage* base;
	if (type == 2) {
		discovery* d = new discovery((float)(rand() % 1000), (float)(rand() % 1000), (float)(rand() % 1000), (int)(rand() % 1000));
		base = (baseMessage*)d;
	}
	else {
		status* s = new status((short)(rand() % 1000), (int)(rand() % 1000));
		base = (baseMessage*)s;
	}
	//הכנסה למערך
	if (arrMessage == NULL)
	{
		arrMessage = (baseMessage**)malloc(sizeof(baseMessage*));
	}
	else
	{
		arrMessage = (baseMessage**)realloc(arrMessage, sizeof(baseMessage*) * (countInArr + 1));
	}
	if (arrMessage == NULL) {
		std::cout << "alocation failed";
		exit(1);
	}
	arrMessage[countInArr] = base;
	countInArr++;
}

void camera::sendToBuffer() {
	for (int i = 0; i < countInArr; i++)
	{
		arrMessage[i]->parseMessage();
		buffer1.addToBuffer((char*)(arrMessage[i]->getMessageBuffer()));
		free(arrMessage[i]);
	}
	free(arrMessage);
	arrMessage = NULL;
	countInArr = 0;
	std::this_thread::sleep_for(1s);
}
//לתקן
void camera::sendToServer() {
	while (isActive) {
		std::this_thread::sleep_for(2s);
		std::cout << " ---send to server--- \n";

		char** buffer = buffer1.getBuffer();


		buffer1.cleanBuffer();
	}
}

void camera::run() {
	int cnt = 0;
	while (isActive)
	{
		std::cout << idCamera << ": run\n";
		for (int i = 0; i < 5; i++)
			generate();
		sendToBuffer();
		cnt++;
		//if (cnt == 10)
		//	isActive = false;
	}
}

void camera::stop() {
	isActive = false;
}

void camera::printDetailes() {
	std::cout << "IdCamera: " << idCamera << "\n";
	for (int j = 0; j < buffer1.getCnt(); j++) {
		std::cout << j << ":" << buffer1.getBuffer()[j][0] << "\n";
	}
}

char camera::getIdCamera() {
	return idCamera;
}

camera::~camera() {
	if (buffer1.getBuffer() != NULL)
		free(buffer1.getBuffer());
}
