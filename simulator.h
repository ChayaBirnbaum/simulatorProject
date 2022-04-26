#ifndef SIMULATOR_H
#define SIMULATOR_H

#pragma once
#include "camera.h"
#include <thread>
#include <iostream>

class simulator
{
private:
	camera* arrCamera[5];
public:
	simulator();
	void begin();
	~simulator();
};

#endif