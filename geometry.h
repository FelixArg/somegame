#pragma once
#ifndef GEOMERTY_H
#define GEOMETRY_H

#include <algorithm>
#include <math.h>
#include "rectangle.h"
#include "circle.h"

class geometry {
public:
	static const float eps;
	static const float pi;
	static bool intersect_rectangles(rectangle a, rectangle b);
	static bool intersect_circles(circle a, circle b);
	static float vector_angle(float x, float y);
};

#endif // !GEOMERTY


