#pragma once
#ifndef OBJECT_CONTROLLER_H
#define OBJECT_CONTROLLER_H

#include "world.h"
#include "rock.h"
#include "tree.h"
#include "human.h"
#include "geometry.h"

class object_controller {
public:
	static int time;
	static int id_counter;
	static bool find_object(world* _world, object* obj);
	static object* find_object(world* _world, int id);
	static void add_new_object(world* _world, object* obj);
	static void delete_destroy_objects(world* _world);
	static void move_object(world* _world, object* obj, float dirx, float diry);
	static void object_attack_object(world* _world, object* obj, object* target);
};

#endif // !OBJECT_CONTROLLER_H
