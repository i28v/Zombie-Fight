#include "normalize.h"
Vector2f normalize(const Vector2f& source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return Vector2f(source.x / length, source.y / length);
	else
		return source;
}