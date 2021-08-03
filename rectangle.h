#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

class rectangle {
protected:
	float x;
	float y;
	float size_x;
	float size_y;
public:
	rectangle(float x, float y, float size_x, float size_y);
	rectangle();
	float get_x();
	float get_y();
	float get_size_x();
	float get_size_y();
	void set_x(float x);
	void set_y(float y);
	void set_size_x(float size_x);
	void set_size_y(float size_y);
};

#endif // !RECTANGLE_H
