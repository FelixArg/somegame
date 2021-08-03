#include "circle.h"

circle::circle(float x, float y, float r) {
	this->x = x;
	this->y = y;
	this->r = r;
}

circle::circle() : circle(0, 0, 1) {

}

float circle::get_x() {
	return x;
}

float circle::get_y() {
	return y;
}

float circle::get_r() {
	return r;
}

void circle::set_x(float x) {
	this->x = x;
}

void circle::set_y(float y) {
	this->y = y;
}

void circle::set_r(float r) {
	this->r = r;
}

