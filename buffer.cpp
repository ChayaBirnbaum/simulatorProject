#include "buffer.h"
#include "discovery.h"
#include "status.h"

buffer::buffer() {
	m = new std::mutex();
	buffer1 = NULL;
	cnt = 0;
}

void buffer::addToBuffer(char* basemessage) {
	m->lock();
	if (buffer1 == NULL) {
		buffer1 = (char**)malloc(sizeof(char*));
	}
	else {
		buffer1 = (char**)realloc(buffer1, sizeof(char*) * (cnt + 1));
	}
	if (buffer1 == NULL) {
		m->unlock();
		std::cout << "alocation failed";
		exit(1);
	}
	buffer1[cnt] = (char*)malloc(sizeof(discovery)>sizeof(status)? sizeof(discovery): sizeof(status));
	if (buffer1[cnt] == NULL) {
		m->unlock();
		std::cout << "alocation failed";
		exit(1);
	}
	strcpy(buffer1[cnt], basemessage);//העתקת תוכן הודעה
	//std::cout << buffer1[cnt] << "\n";
	m->unlock();
	cnt = cnt + 1;
}

char** buffer::getBuffer() {
	return buffer1;
}

int buffer::getCnt() {
	return cnt;
}

void buffer::cleanBuffer() {
	m->lock();
	for (int i = 0; i < cnt; i++)
		free(buffer1[cnt]);
	free(buffer1);
	cnt = 0;
	m->unlock();
}

buffer::~buffer() {
	delete(m);
	cleanBuffer();
}