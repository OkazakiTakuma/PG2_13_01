#pragma once
#include "Vector2.h"
class Object {
public:
	virtual void Update();
	virtual void Move(char* keys);
	virtual void Draw();
	Vector2 pos_ = {};
	Vector2 radius_ = {};
	Vector2 speed_ = {};
	bool isActive_=true;
};
