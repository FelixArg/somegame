#pragma once
#ifndef HUMAN_H
#define HUMAN_H

#include "object.h"
#include "imovable.h"
#include "idestroyable.h"
#include "geometry.h"
#include "idealdamage.h"
#include <string>

class human : public object, public imovable, public idestroyable, public idealdamage {
protected:
	int team;
	std::string name;
public:
	human(int id, float posx, float posy, std::string name, int team);
	std::string get_name();
	int get_team();
	void change_team(int team);
	void move_to(float dirx, float diry) override;
	void turn_around(float angle) override;
	std::string to_string() override;
};

#endif // !HUMAN_H
