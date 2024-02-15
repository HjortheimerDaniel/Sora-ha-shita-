#include "GameClear.h"

void GameClear::Initialize() {

	clear.pos.x = 0;
	clear.pos.y = 0;
	clear.emitter.x = 0;
	clear.emitter.y = -50;
	clear.emitterSize.x = 1280;
	clear.emitterSize.y = 10;
	clear.handle = Novice::LoadTexture("./Sprites/GameClearText.png");

	for (int i = 0; i < MAXNUMBER; i++) {
		coins[i].x = -50;
		coins[i].y = 0;
		isFalling[i] = false;
		speed[i] = 3;
	}

	clear.animation = 0;
	clear.frames = 0;
	seed = (unsigned int)time(nullptr);
	srand(seed);
	coinSize = 30;
	coinHandle = Novice::LoadTexture("./Sprites/Coin.png");
	delay = 0;

}

void GameClear::CoinAnimation() {

	clear.frames++;

	if (clear.frames >= 7) {
		clear.animation++;
		clear.frames = 0;
	}

	if (clear.animation >= 6) {
		clear.animation = 0;
	}

}

void GameClear::FallingCoins() {

	delay++;

	if (delay >= 20) {
		delay = 0;
	}

	for (int i = 0; i < MAXNUMBER; i++) {
		if (!isFalling[i]&& delay == 0) {
			isFalling[i] = true;
			coins[i].x = clear.emitter.x + rand() % ((int)clear.emitterSize.x);
			coins[i].y = clear.emitter.y + rand() % ((int)clear.emitterSize.y) - clear.emitterSize.y/2;
			speed[i] = 0;
			break;
		}
	}

	for (int i = 0; i < MAXNUMBER; i++) {
		speed[i] = 3;
		if (isFalling[i]) {
			coins[i].y += speed[i];
		}
	}

	for (int i = 0; i < MAXNUMBER; i++) {
		if (coins[i].y >= 850) {
			isFalling[i] = false;
		}
	}
}

void GameClear::Update() {

	CoinAnimation();
	FallingCoins();

}

void GameClear::DrawCoins() {

	for (int i = 0; i < MAXNUMBER; i++) {
		Novice::DrawQuad(
		    (int)coins[i].x, (int)coins[i].y, (int)coins[i].x + coinSize, (int)coins[i].y,
		    (int)coins[i].x, (int)coins[i].y + coinSize, (int)coins[i].x + coinSize,
		    (int)coins[i].y + coinSize,
		    30 * clear.animation, 0, 30, 30, coinHandle, WHITE);
	}

}

void GameClear::Draw() {

	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	DrawCoins();
	Novice::DrawSprite((int)clear.pos.x, (int)clear.pos.y, clear.handle, 1, 1, 0.0f, WHITE);
	

}
