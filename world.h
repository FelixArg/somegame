#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "object.h"
#include <vector>

class world {
private:
	int width;
	int height;
public:
	std::vector<object*> objects;
	world();
	world(int width, int height);
	~world();
	int get_width();
	int get_height();
};

#endif // !WORLD_H
