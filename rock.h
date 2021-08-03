#pragma once
#ifndef ROCK
#define ROCK

#include "object.h"
#include "idestroyable.h"

class rock : public object, public idestroyable {
public:
	rock(int id, int max_dur, int dur, float pos_x, float pos_y, float size_r);
	std::string to_string() override;
};

#endif // !ROCK