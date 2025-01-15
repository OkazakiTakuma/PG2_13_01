#pragma once
#include "Object.h"
class Bullet : public Object {
public:
	Bullet(Vector2 pos, Vector2 radius, Vector2 speed);
	void Update() override;
	void Draw() override;
};
