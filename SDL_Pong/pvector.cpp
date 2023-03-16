#include "pvector.h"
#include <cmath>

PVector::PVector() : x(0), y(0)
{ }

PVector::PVector(float x, float y) : x(x), y(y)
{ }

float PVector::getLength()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}
