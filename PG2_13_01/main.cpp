#include "Enemy.h"
#include "Hit.h"
#include "Object.h"
#include "Player.h"
#include "Vector2.h"
#include <Novice.h>

const char kWindowTitle[] = "LC1B_04_オカザキ_タクマ";
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	Player* player;
	Enemy* enemy[2];
	player = new Player;
	Vector2 EPos[2] = {
	    {640, 400},
        {640, 500}
    };
	Vector2 ERadius[2] = {
	    {16, 16},
        {16, 16}
    };
	Vector2 ESpeed[2] = {
	    {10,  0},
        {-10, 0}
    };
	for (int i = 0; i < 2; i++) {
		enemy[i] = new Enemy(EPos[i], ERadius[i], ESpeed[i]);
	}
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		if (keys[DIK_SPACE]) {
		}
		///
		/// ↑更新処理ここまで
		///
		player->Move(keys);
		for (int i = 0; i < 2; i++) {
			enemy[i]->Move(keys);
		}
		for (int i = 0; i < 2; i++) {
			if (player->isBullet && enemy[i]->isActive_) {
				enemy[i]->isHit_ = Hit(enemy[i]->pos_, enemy[i]->radius_, player->playerBullet->pos_, player->playerBullet->radius_);
			}
		}
		///
		/// ↓描画処理ここから
		///
		player->Draw();
		for (int i = 0; i < 2; i++) {
			enemy[i]->Draw();
		}
		Novice::ScreenPrintf(0, 0, "enemyA isAlive=%d", enemy[0]->isActive_);
		Novice::ScreenPrintf(0, 20, "enemyA isAlive=%d", enemy[1]->isActive_);
		Novice::ScreenPrintf(0, 40, "WASD : player Move");
		Novice::ScreenPrintf(0, 60, "shot : SPACE");
		Novice::ScreenPrintf(0, 80, "enemy respown : R");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	for (int i = 0; i < 2; i++) {
		delete enemy[i];
	}
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
