#pragma once
#ifndef IDESTROYABLE_H
#define IDESTROYABLE_H

class idestroyable {
protected:
	int max_durability;
	int durability;
public:
	virtual int get_durability();
	virtual int get_max_durability();
	virtual void change_durability(int);
};


#endif // !IDESTROYABLE_H
