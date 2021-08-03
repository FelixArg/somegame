#include "idealdamage.h"

idealdamage::idealdamage(int damage, float attack_range) {
	this->attack_range = attack_range;
	this->damage = damage;
}

idealdamage::idealdamage() : idealdamage(0, 0) {

}

float idealdamage::get_attack_range() {
	return attack_range;
}

int idealdamage::get_damage() {
	return damage;
}

void idealdamage::attack(idestroyable* target) {
	target->change_durability(-damage);
}