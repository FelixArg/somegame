#pragma once
#ifndef TREE
#define TREE

#include "object.h"
#include "idestroyable.h"

class tree : public object, public idestroyable {
public:
	tree(int id, int max_dur, int dur, float pos_x, float pos_y, float size_r);
	std::string to_string() override;
};

#endif // !TREE

