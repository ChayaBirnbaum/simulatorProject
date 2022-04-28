#ifndef SIMULATOR_H
#define SIMULATOR_H

#pragma once
#include "camera.h"
#include <thread>
#include <iostream>
#define len_arrCamera 5

class simulator
{
private:
	camera* arrCamera[len_arrCamera];
public:
	simulator();
	void begin();
	void printAllCmera();
	~simulator();
};

#endif