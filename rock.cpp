#include "rock.h"

rock::rock(int id, int max_dur, int dur, float pos_x, float pos_y, float size_x) : object(id, pos_x, pos_y, size_x, 0.0f) {
	max_durability = max_dur;
	durability = dur;
}


std::string rock::to_string() {
	return "rock";
}