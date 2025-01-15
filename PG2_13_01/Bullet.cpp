#include "Bullet.h"
#include<Novice.h>
Bullet::Bullet(Vector2 pos, Vector2 radius, Vector2 speed) {
	pos_ = pos;
	radius_ = radius;
	speed_ = speed;

}
void Bullet::Update() { 
	pos_.y -= speed_.y;
	
}
void Bullet::Draw() { Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_.x), static_cast<int>(radius_.y), 0.0f, WHITE, kFillModeSolid); }
