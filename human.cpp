#include "human.h"

const float TICK = 0.025f;
const float SIZE_R = 10.0f;
const int HEALTH = 100;
const int MAX_HEALTH = 100;
const float SPEED = 5.0f;
const float MAX_SPEED = 5.0f;
const float TURN_SPEED = 0.40f;
const float ATTACK_RANGE = 7.0f;
const int DAMAGE = 10;

human::human(int id, float posx, float posy, std::string name, int team = 0) : object(id, posx, posy, SIZE_R, 0.0f) {
	durability = HEALTH;
	max_durability = MAX_HEALTH;
	speed = SPEED;
	max_speed = MAX_SPEED;
	turn_speed = TURN_SPEED;
	damage = DAMAGE;
	attack_range = ATTACK_RANGE;
	this->name = name;
	this->team = team;
}

int human::get_team() {
	return team;
}

void human::change_team(int team) {
	this->team = team;
}

std::string human::get_name() {
	return name;
}

void human::move_to(float dirx, float diry) {
	float dx = dirx - hitbox.get_x();
	float dy = diry - hitbox.get_y();
	int sgx = 1;
	int sgy = 1;

	if (dx < 0) {
		sgx = -1;
		dx = -dx;
	}

	if (dy < 0) {
		sgy = -1;
		dy = -dy;
	}

	float dist = sqrt(dx * dx + dy * dy);

	if (dist <= speed) {
		hitbox.set_x(hitbox.get_x() + dx * sgx);
		hitbox.set_y(hitbox.get_y() + dy * sgy);
	}
	else {
		float rel = (float)speed / dist;
		hitbox.set_x(hitbox.get_x() + rel * dx * sgx);
		hitbox.set_y(hitbox.get_y() + rel * dy * sgy);
	}
}

void human::turn_around(float angle) {
	int sgn = (angle < 0 ? -1 : 1);
	if (angle * sgn < turn_speed)
		face_angle += angle;
	else
		face_angle += turn_speed * sgn;
	if (face_angle < 0) {
		face_angle += 2 * geometry::pi;
	}
}

std::string human::to_string() {
	return "human";
}