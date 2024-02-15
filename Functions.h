#pragma once
#include "Struct.h"
#define _USE_MATH_DEFINES_
#include <math.h>

float Clamp(float t, float min, float max);

//float Tunneling(Vector2 dist, Vector2 player, Vector2 floor, Vector2 floorEnd, Vector2 endStart, Vector2 normalize, Vector2 distPF, float accY, float velY);

bool CheckCollision(Vector2 pos1, Vector2 pos2, Vector2 size1, Vector2 size2);

bool CheckCollisionHead(Vector2 pos1, Vector2 pos2, Vector2 size1, Vector2 size2, float dist);