#ifndef CAMERA_H
#define CAMERA_H

#pragma once
#include "baseMessage.h"
#include "buffer.h"
#include "discovery.h"
#include "status.h"
#include <thread>
using namespace std::literals::chrono_literals;

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
	void generate();// ������� ������� ����� ������� ������� ������� �����  �������  ����� �� ����� ���� ������
	void sendToBuffer(); // ����� �� �� ���� �������, ����� �� ����� ������� ������� ������ �� ������� ������ �� ������� �buffer, ������ �� ���� �������
	void run(); // ����� � generate �  send  �������� ������ �� ��� isActive ��� � true ��� �� �������� ����
	void stop(); // ������ �� isActive � false
	void sendToServer();
	void printDetailes();
	char getIdCamera();
	buffer getBuffer();
	~camera();
};

#endif