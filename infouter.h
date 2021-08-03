#pragma once
#ifndef INFOUTER_H
#define INFOUTER_H

#include "world.h"
#include "idestroyable.h"
#include <fstream>
#include <string>
#include <vector>

class infouter {
public:
	static bool fout(std::string filename, std::vector<world*> worlds);
};

#endif // !INFOUTER_H
