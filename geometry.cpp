#include "geometry.h"

const float geometry::eps = 1e-6f;
const float geometry::pi = 3.1415926535897932384626433832795028841971f;

bool geometry::intersect_rectangles(rectangle a, rectangle b) {
	if (a.get_x() > b.get_x())
		std::swap(a, b);

	if (b.get_x() >= a.get_x() + a.get_size_x())
		return false;

	if (a.get_y() > b.get_y())
		std::swap(a, b);

	return (b.get_y() < a.get_y() + a.get_size_y());
}

bool geometry::intersect_circles(circle a, circle b) {
	float sum_r_square = a.get_r() + b.get_r();
	sum_r_square *= sum_r_square;
	float dist_square = (a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y());
	return (sum_r_square > dist_square);
}

float geometry::vector_angle(float x, float y) {
	if (x == 0 && y == 0)
		return 0;

	if (x == 0 && y > 0)
		return pi / 2;
	else if (x == 0 && y < 0)
		return 3 * pi / 2;

	if (y == 0 && x > 0)
		return 0.0f;
	else if (y == 0 && x < 0)
		return pi;

	float tg = y / x;
	if (tg < 0)
		tg = -tg;

	if (x > 0 && y > 0)
		return atan(tg);
	else if (x < 0 && y > 0)
		return atan(tg) + pi / 2;
	else if (x < 0 && y < 0)
		return atan(tg) + pi;
	else
		return atan(tg) + 3 * pi / 2;
}