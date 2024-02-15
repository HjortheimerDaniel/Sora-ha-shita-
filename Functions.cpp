#include "Functions.h"

float Clamp(float t, float min, float max) {
	if (t < min) {
		return min;
	} else if (t > max) {
		return max;
	}

	return t;
}

bool CheckCollision(Vector2 pos1, Vector2 pos2, Vector2 size1, Vector2 size2) {
	if (pos1.x < pos2.x + size2.x && pos2.x < pos1.x + size1.x && pos1.y < pos2.y + size2.y &&
	    pos2.y < pos1.y + size1.y) {
		return true;
	}
	return false;
}

//bool CheckCollisionHead(Vector2 pos1, Vector2 pos2, Vector2 size1, Vector2 size2, float dist) {
//	if (pos1.x < pos2.x + size2.x && pos2.x < pos1.x + size1.x && pos2.y - pos1.y >= 1) {
//		return true;
//	}
//	return false; }

//float Tunneling(
//    Vector2 dist, Vector2 player, Vector2 floor, Vector2 floorEnd, Vector2 endStart,
//    Vector2 normalize, Vector2 distPF, float accY,
//    float velY) {
//	
//	dist.x = player.x - floor.x;
//	dist.y = player.y - floor.y;
//	endStart.x = floorEnd.x - floor.x;
//	endStart.y = floorEnd.y - floor.y;
//
//	float length = sqrtf(endStart.x * endStart.x + endStart.y * endStart.y);
//
//	normalize.x = endStart.x / length;
//	normalize.y = endStart.y / length;
//
//	float t = (dist.x * normalize.x + dist.y * normalize.y) / length;
//
//	t = Clamp(t, 0, 1);
//
//	distPF.x = (1.0f - t) * floor.x + t * floorEnd.x;
//	distPF.y = (1.0f - t) * floor.y + t * floorEnd.y;
//
//	float distance = sqrtf(
//	    (player.x - distPF.x) * (player.x - distPF.x) +
//	    (player.y - distPF.y) * (player.y - distPF.y));
//
//	if (distance < 40) {
//		accY = 0;
//		velY = 0;
//	}
//	
//}


