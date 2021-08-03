#pragma once
#ifndef IMOVABLE_H
#define IMOVABLE_H

class imovable {
protected:
	float speed;
	float max_speed;
	float turn_speed;
public:
	virtual void move_to(float dirx, float diry);
	virtual float get_speed();
	virtual float get_max_speed();
	virtual void turn_around(float angle);
};


#endif // !IMOVABLE_H
