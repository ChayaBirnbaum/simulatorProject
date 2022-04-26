#ifndef CAMERA_H
#define CAMERA_H

#pragma once
#include "baseMessage.h"
#include "buffer.h"
#include "discovery.h"
#include "status.h"

class camera
{
private:
	char idCamera;
	baseMessage** arrMessage = NULL;
	int countInArr = 0;
	buffer buffer1;
	bool isActive = true;
public:
	camera(char);
	void generate();// פונקציה שמייצרת הודעה מנתונים אקראיים ומוסיפה למערך  ההודעות  יכולה גם לחולל מספר הודעות
	void sendToBuffer(); // עוברת על כל מערך ההודעות, ממירה את נתוני ההודעות לבייטים מעבירה את הנתונים מהמערך של ההודעות לbuffer, ומאפסת את מערך ההודעות
	void run(); // קוראת ל generate ו  send  לסירוגין בלולאה כל עוד isActive שוה ל true כמו כן בפונקציה יהיה
	void stop(); // מעדכנת את isActive ל false
	void printDetailes();
	char getIdCamera();
	buffer getBuffer();
};

#endif