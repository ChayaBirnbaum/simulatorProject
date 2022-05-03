#ifndef STATUS_H
#define STATUS_H

#include "baseMessage.h"
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>


class status :baseMessage
{
public:
	short status1;
	status(unsigned char*, int);
	status(short, int);
	void  parseMessage();
	void  parseBack();
	void  print();
	void printToFile(std::ofstream);
};

#endif