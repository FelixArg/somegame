#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

class circle {
protected:
	float x;
	float y;
	float r;
public:
	circle(float x, float y, float r);
	circle();
	float get_x();
	float get_y();
	float get_r();
	void set_x(float x);
	void set_y(float y);
	void set_r(float r);
};

#endif // !CIRCLE_H

