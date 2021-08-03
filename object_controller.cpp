#include "object_controller.h"

int object_controller::time = 0;
int object_controller::id_counter = 1;

bool object_controller::find_object(world* _world, object* obj) {
	for (object* o : _world->objects) {
		if (o == obj)
			return true;
	}
	return false;
}

object* object_controller::find_object(world* _world, int id) {
	for (object* o : _world->objects) {
		if (o->get_id() == id)
			return o;
	}
	return nullptr;
}

void object_controller::add_new_object(world* _world, object* obj) {
	_world->objects.emplace_back(obj);
}
void object_controller::delete_destroy_objects(world* _world) {
	for (int i = 0; i < _world->objects.size(); i++) {
		if (dynamic_cast<idestroyable*>(_world->objects[i])) {
			if (dynamic_cast<idestroyable*>(_world->objects[i])->get_durability() <= 0) {
				std::swap(_world->objects[i], _world->objects.back());
				delete _world->objects.back();
				_world->objects.pop_back();
			}
		}
	}
}

void object_controller::move_object(world* _world, object* obj, float dirx, float diry) {
	if (!find_object(_world, obj))
		return;
	if (dynamic_cast<imovable*>(obj)) {
		float angle_to = geometry::vector_angle(dirx - obj->get_position_x(), diry - obj->get_position_y());
		if (abs(obj->get_face_angle() - angle_to) < geometry::eps) {
			int old_pos_x = obj->get_position_x();
			int old_pos_y = obj->get_position_y();
			dynamic_cast<imovable*>(obj)->move_to(dirx, diry);
			bool move_back = false;
			for (object* o : _world->objects) {
				if (o != obj) {
					if (geometry::intersect_circles(obj->get_hitbox(), o->get_hitbox())) {
						move_back = true;
						break;
					}
				}
			}

			if (move_back)
				dynamic_cast<imovable*>(obj)->move_to(old_pos_x, old_pos_y);
		}
		else {
			float dangle = angle_to - obj->get_face_angle();
			if (abs(dangle) > geometry::pi) {
				int sgn = (dangle < 0 ? -1 : 1);
				dangle *= sgn;
				dangle = 2 * geometry::pi - dangle;
				if (sgn > 0)
					dangle *= -1;
			}
			dynamic_cast<imovable*>(obj)->turn_around(dangle);
		}
	}
}

void object_controller::object_attack_object(world* _world, object* obj, object* target) {
	if (!find_object(_world, obj))
		return;
	if (!find_object(_world, target))
		return;
	if (!dynamic_cast<idealdamage*>(obj))
		return;
	if (!dynamic_cast<idestroyable*>(target))
		return;
	float dist_r = sqrt((obj->get_position_x() - target->get_position_x()) * (obj->get_position_x() - target->get_position_x()) +
		(obj->get_position_y() - target->get_position_y()) * (obj->get_position_y() - target->get_position_y()));
	float sum_r_plus_attack_range = obj->get_size() + target->get_size() + dynamic_cast<idealdamage*>(obj)->get_attack_range();
	if (dist_r > sum_r_plus_attack_range)
		return;
	float angle_to = geometry::vector_angle(target->get_position_x() - obj->get_position_x(), target->get_position_y() - obj->get_position_y());
	if (abs(obj->get_face_angle() - angle_to) > geometry::eps) {
		if (!dynamic_cast<imovable*>(obj))
			return;
		float dangle = angle_to - obj->get_face_angle();
		if (abs(dangle) > geometry::pi) {
			int sgn = (dangle < 0 ? -1 : 1);
			dangle *= sgn;
			dangle = 2 * geometry::pi - dangle;
			if (sgn > 0)
				dangle *= -1;
		}
		dynamic_cast<imovable*>(obj)->turn_around(dangle);
	}
	else {
		dynamic_cast<idealdamage*>(obj)->attack(dynamic_cast<idestroyable*>(target));
	}
}