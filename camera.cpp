#include "camera.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

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
	std::cout << idCamera << ": generate\n";

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

void camera::run() {
	while (isActive)
	{
		std::cout << idCamera << ": run\n";
		for (int i = 0; i < 5; i++)
			generate();
		sendToBuffer();
		sendToServer();
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

void camera::sendToServer() {
     	//עובד מקומית, צריך להעביר לשרת

		std::this_thread::sleep_for(2s);

		std::string name = "all.txt";
		if (idCamera == 'A')
			name = "cameraA.txt";
		if (idCamera == 'B')
			name = "cameraB.txt";
		if (idCamera == 'C')
			name = "cameraC.txt";
		if (idCamera == 'D')
			name = "cameraD.txt";
		if (idCamera == 'E')
			name = "cameraE.txt";

		std::ofstream cameraFile(name, std::ios::app);

		char** buffer2 = buffer1.getBuffer();

		if (buffer1.getCnt() > 0) {
			if (cameraFile.is_open())
			{
				std::cout << buffer1.getCnt();
				for (int i = 0; i < buffer1.getCnt(); i++) {
					int n = int(*(buffer2[0]));
					if ( n == 2) {
						cameraFile << idCamera << ": ";
						discovery d((unsigned char*)(buffer2[i]), 2);
						d.parseBack();
						cameraFile << "messageType:2, angle:" << d.angle
							<< " distance, " << d.distance
							<< " speed " << d.speed << std::endl;
					}
					else {
						cameraFile << idCamera << ": ";
						status s((unsigned char*)(buffer2[i]), 2);
						s.parseBack();
						cameraFile << "messageType:2, status:" << s.status1 << std::endl;
					}
				}
				std::cout << " ---send to file--- \n";
			}
			else
			{
				std::cout << "Couldn't open cmara " + idCamera;
				std::cout << +" file for writing.\n";
			}
		}
		cameraFile.close();
}