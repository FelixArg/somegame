#pragma once
#ifndef IDEALDAMAGE_H
#define IDEALDAMAGE_H

#include "idestroyable.h"

class idealdamage {
protected:
	int damage;
	float attack_range;
public:
	idealdamage(int damage, float attack_range);
	idealdamage();
	virtual int get_damage();
	virtual float get_attack_range();
	virtual void attack(idestroyable* target);
};

#endif //!IDEALDAMAGE_H