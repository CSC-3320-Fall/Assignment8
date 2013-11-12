#include <stdbool.h>

#ifndef ASSIGNMENT8_HEADER
#define ASSIGNMENT8_HEADER
typedef struct point { long resn; float x; float y; float z; bool located; } point;
float euclidean_distance(point a, point b);
point set_point(bool located);
#endif