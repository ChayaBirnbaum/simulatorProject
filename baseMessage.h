#ifndef BASEMESSAGE_H
#define BASEMESSAGE_H

#pragma once
#include <stdlib.h>
class baseMessage
{
protected:
	unsigned char* messageBuffer;
	int messageId;
	int messageType;
public:
	baseMessage(int);
	virtual void  parseMessage();
	virtual void  parseBack();
	virtual void  print();
	unsigned char* getMessageBuffer();
	~baseMessage();
};

#endif