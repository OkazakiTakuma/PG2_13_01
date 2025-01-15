#pragma once
#include "Object.h"
#include"Bullet.h"
class Player : public Object {
public:
	Player();
	~Player();
	void Move(char *keys) override;
	void Draw() override;
	bool isBullet;
	Vector2 bulletRadius_;
	Bullet* playerBullet;
	
};
