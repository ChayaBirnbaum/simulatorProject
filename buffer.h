#ifndef BUFFER_H
#define BUFFER_H

#pragma once
#include "baseMessage.h"
#include <string.h>
#include <iostream>

class buffer
{
protected:
	char** buffer1;
	int cnt;
public:
	buffer();
	//void addToBuffer(baseMessage);// הוספת הודעה
	void addToBuffer(char*);// הוספת הודעה
	char** getBuffer();// מחזירה את ה buffer
	void cleanBuffer();// ריקון ה buffer

};

#endif