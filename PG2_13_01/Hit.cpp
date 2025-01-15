#include"Vector2.h"
#include<math.h>
#include"Hit.h"

int Hit(Vector2 posA, Vector2 sizeA, Vector2 posB, Vector2 sizeB) {
	if (sqrtf(powf(posA.x - posB.x, 2) + powf(posA.y - posB.y, 2)) <= sizeA.x + sizeB.x) {
		return 1;
	} else {
		return 0;
	}
}
