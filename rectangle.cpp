#include "rectangle.h"

rectangle::rectangle(float x, float y, float size_x, float size_y) {
	this->x = x;
	this->y = y;
	this->size_x = size_x;
	this->size_y = size_y;
}

rectangle::rectangle() : rectangle(0, 0, 1, 1) {

}

float rectangle::get_x() {
	return x;
}

float rectangle::get_y() {
	return y;
}

float rectangle::get_size_x() {
	return size_x;
}

float rectangle::get_size_y() {
	return size_y;
}

void rectangle::set_x(float x) {
	this->x = x;
}

void rectangle::set_y(float y) {
	this->y = y;
}

void rectangle::set_size_x(float size_x) {
	this->size_x = size_x;
}

void rectangle::set_size_y(float size_y) {
	this->size_y = size_y;
}