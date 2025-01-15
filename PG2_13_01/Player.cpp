#include "Player.h"
#include<Novice.h>
#include"Bullet.h"
Player::Player() { 
	isBullet = false;
	pos_ = {640, 600};
	radius_ = {32, 32};
	speed_ = {10, 10};
	bulletRadius_ = {16, 16};
}
Player::~Player() {
	if (isBullet) {
	delete playerBullet;
	}
}

void Player::Move(char* keys) {
	if (!isBullet && keys[DIK_SPACE]) {
		isBullet = true;
		playerBullet = new Bullet(pos_,bulletRadius_,speed_);
	}
	if (keys[DIK_W]) {
		pos_.y -= speed_.y;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_.x;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_.y;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_.x;
	}
	if (isBullet) {
		playerBullet->Update();
		if (playerBullet->pos_.y <= -playerBullet->radius_.y) {
			delete playerBullet;
			isBullet = false;
		}
	}
}
void Player::Draw() {
	if (isBullet) {
		playerBullet->Draw();
	}	
	Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_.x), static_cast<int>(radius_.y), 0.0f, GREEN, kFillModeSolid);
}
