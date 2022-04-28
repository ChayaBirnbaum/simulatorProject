#include "buffer.h"
#include "discovery.h"
#include "status.h"

buffer::buffer() {
	buffer1 = NULL;
	cnt = 0;
}

void buffer::addToBuffer(char* basemessage) {
	if (buffer1 == NULL) {
		buffer1 = (char**)malloc(sizeof(char*));
	}
	else {
		buffer1 = (char**)realloc(buffer1, sizeof(char*) * (cnt + 1));
	}
	if (buffer1 == NULL) {
		std::cout << "alocation failed";
		exit(1);
	}
	buffer1[cnt] = (char*)malloc(sizeof(discovery)>sizeof(status)? sizeof(discovery): sizeof(status));
	if (buffer1[cnt] == NULL) {
		std::cout << "alocation failed";
		exit(1);
	}
	strcpy(buffer1[cnt], basemessage);//העתקת תוכן הודעה
	//std::cout << buffer1[cnt] << "\n";
	cnt = cnt + 1;
}

char** buffer::getBuffer() {
	return buffer1;
}

int buffer::getCnt() {
	return cnt;
}

void buffer::cleanBuffer() {
	for (int i = 0; i < cnt; i++)
		free(buffer1[cnt]);
	free(buffer1);
}