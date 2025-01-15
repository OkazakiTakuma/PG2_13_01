#pragma once
#include "Object.h"
class Enemy : public Object {
public:
	Enemy(Vector2 pos, Vector2 radius, Vector2 speed);
	void Move(char* keys) override;
	void Draw() override;
	static int life;
	int isHit_;
};
