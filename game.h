#pragma once
#ifndef GAME_H
#define GAME_H

#include "object_controller.h"
#include "infouter.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <random>

class game {

private:

	bool run;

public:

	game();

	int execute();

	void exit();
};


#endif //!GAME_H