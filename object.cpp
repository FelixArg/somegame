#include "object.h"

object::object(int id, float x, float y, float r, float face_angle) {
	hitbox = circle(x, y, r);
	this->face_angle = face_angle;
	this->id = id;
}

object::object(int id, circle hitbox, float angle) {
	this->hitbox = hitbox;
	this->face_angle = angle;
	this->id = id;
}

object::object(int id) : object(id, 0, 0, 0, 0) {

}

circle object::get_hitbox() {
	return hitbox;
}

float object::get_position_x() {
	return hitbox.get_x();
}

float object::get_position_y() {
	return hitbox.get_y();
}

float object::get_size() {
	return hitbox.get_r();
}

float object::get_face_angle() {
	return face_angle;
}

int object::get_id() {
	return id;
}

std::string object::to_string() {
	return "object";
}