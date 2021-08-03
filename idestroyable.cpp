#include "idestroyable.h"


int idestroyable::get_durability() {
	return durability;
}

int idestroyable::get_max_durability() {
	return max_durability;
}

void idestroyable::change_durability(int ddur) {
	durability += ddur;
	if (durability > max_durability)
		durability = max_durability;
}
