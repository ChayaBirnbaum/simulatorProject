#ifndef SIMULATOR_H
#define SIMULATOR_H

#pragma once
#include "camera.h"
#include "configur.h"
#include <thread>
#include <iostream>
#define MAX_CAMERA 10

class simulator
{
private:
	camera** arrCamera;
	configur* config;
public:
	simulator();
	void begin();
	void printAllCmera();
	~simulator();
};

#endif