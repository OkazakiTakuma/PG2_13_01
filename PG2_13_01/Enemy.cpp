#include "Enemy.h"
#include <Novice.h>
int Enemy::life = 1;
Enemy::Enemy(Vector2 pos, Vector2 radius, Vector2 speed) {
	pos_ = pos;
	radius_ = radius;
	speed_ = speed;
	isHit_ = 0;
}
void Enemy::Move(char* keys) {
	if (isActive_) {
		
		if (life<=0) {
			isActive_ = false;
		}
		pos_.x += speed_.x;
		if (pos_.x + radius_.x >= 1280 || pos_.x <= radius_.x) {
			speed_.x = -speed_.x;
		}
		if (isHit_) {
			life -= 1;
		}
	} else {
		if (keys[DIK_R]) {
			life = 1;
			isActive_ = true;
			
		}
		
	}
}
void Enemy::Draw() {
	if (isActive_) {
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_.x), static_cast<int>(radius_.y), 0.0f, RED, kFillModeSolid);
	}
}
