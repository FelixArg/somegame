#pragma once
#ifndef  OBJECT_H
#define OBJECT_H

#include "circle.h"
#include <string>

class object {
protected:
	circle hitbox;
	float face_angle;
	int id;
public:
	object(int id, circle hitbox, float angle);
	object(int id, float x, float y, float r, float angle);
	object(int id);
	virtual circle get_hitbox();
	virtual float get_position_x();
	virtual float get_position_y();
	virtual float get_size();
	virtual float get_face_angle();
	virtual int get_id();
	virtual std::string to_string();
};

#endif //  OBJECT_H