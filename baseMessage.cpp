#include "baseMessage.h"

baseMessage::baseMessage(int id) {
	this->messageId = id;
	this->messageBuffer = NULL;
	this->messageType = 0;
}


unsigned char* baseMessage::getMessageBuffer() {
	return this->messageBuffer;
}
void  baseMessage::parseMessage() {

}

void  baseMessage::parseBack() {

}

void  baseMessage::print() {

}

baseMessage::~baseMessage() {
	if (this->messageBuffer != NULL)
		free(this->messageBuffer);
}