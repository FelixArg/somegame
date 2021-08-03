#include "tree.h"

tree::tree(int id, int max_dur, int dur, float pos_x, float pos_y, float size_r) : object(id, pos_x, pos_y, size_r, 0.0f) {
	max_durability = max_dur;
	durability = dur;
}

std::string tree::to_string() {
	return "tree";
}