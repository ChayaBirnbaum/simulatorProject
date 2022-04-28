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
	//יש לשלוח לסרבר
	/*std::this_thread::sleep_for(2s);*/
	/*
	לפי הההגדרה של מספר הודעות בשניה  תשלח את הbuffer של כל מצלמה לשרת בתוספת תו המצין את ה מזהה של המצלמה ממנו הגיעה ההודעה (הוסיפי קוד זה בפונקציהsend) ותרוקן את הבפר. 


	*/

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
	for (int j = 0; j < getBuffer().getCnt(); j++) {
		std::cout << j << ":" << getBuffer().getBuffer()[j][0] << "\n";
	}
}

void camera::sendToServer() {

}

char camera::getIdCamera() {
	return idCamera;
}

buffer camera::getBuffer()
{
	return buffer1;
}

camera::~camera() {
	if (buffer1.getBuffer() != NULL)
		free(buffer1.getBuffer());
}
