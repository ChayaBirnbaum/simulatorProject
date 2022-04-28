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
	void addToBuffer(char*);// ����� �����
	char** getBuffer();// ������ �� � buffer
	int getCnt();
	void cleanBuffer();// ����� � buffer
};

#endif