#include "game.h"

std::mt19937 rng(std::chrono::high_resolution_clock().now().time_since_epoch().count());

game::game() {
	run = true;
}

int game::execute() {
	world* _world = new world(300, 300);
	object_controller::add_new_object(_world, new rock(object_controller::id_counter++, 100, 100, 100, 100, 10));
	object_controller::add_new_object(_world, new tree(object_controller::id_counter++, 50, 50, 120, 100, 5));
	object_controller::add_new_object(_world, new human(object_controller::id_counter++, 200, 200, "Vova", 0));
	infouter::fout("test.txt", { _world });

	double time_measure = 0;
	while (run) {
		auto start = std::chrono::high_resolution_clock::now();
		for (object* obj : _world->objects) {
			if (obj->get_id() == 3) {
				object_controller::move_object(_world, obj, 120, 100);
				object_controller::object_attack_object(_world, obj, object_controller::find_object(_world, 2));
			}
		}

		object_controller::delete_destroy_objects(_world);
		infouter::fout("test.txt", { _world });
		object_controller::time++;

		//std::this_thread::sleep_for(std::chrono::milliseconds(300));
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		time_measure += duration.count() / 1e6;
		system("cls");
		std::cout << std::fixed << time_measure / (object_controller::time + 1);
	}

	_world->~world();

	return 0;
}


void game::exit() {
	run = false;
}

