#include "world.h"

world::world(int w, int h) {
	width = w;
	height = h;
}

world::world() : world(0, 0) {}

int world::get_height() {
	return height;
}

int world::get_width() {
	return width;
}

world::~world() {
	for (object* obj : objects) {
		delete obj;
	}
}