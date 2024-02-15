#include "Wind.h"



void Wind::InitializeWind() {

	for (int i = 0; i < MAXPARTICLES; i++) {
		windParticles[i].x = -40;
		windParticles[i].y = 0;
		radius[i] = 2;
		speedY[i] = 2;
		speedX[i] = 2;
		isBlowing[i] = false;
	}
	emitter = {0, -50};
	emitterSize = {1280, 10};
	seed = (unsigned int)time(nullptr);
	srand(seed);
	windMiddle = 640;
	windTimer = 0;
	gravityReverse = 1;
	isGravityReversed = false;
	isScrollXBackwardWind = false;
	isScrollXForwardWind = false;
	scrollSpeed = 5;

}

void Wind::BlowWind() {

	for (int i = 0; i < MAXPARTICLES; i++) {
		if (!isBlowing[i] && windTimer == 0) {
			isBlowing[i] = true;
			startBlowing = true;
			windParticles[i].x = windMiddle + rand() % ((int)emitterSize.x) - (int)emitterSize.x / 2;
			windParticles[i].y = emitter.y + rand() % ((int)emitterSize.y) - (int)emitterSize.y / 2;
			speedY[i] = 0;
			break;
		}
	}

	if (startBlowing) {
		windTimer++;
	}

	if (windTimer >= 10) {
		startBlowing = false;
		windTimer = 0;
	}

	for (int i = 0; i < MAXPARTICLES; i++) {

		speedY[i] = rand() % 4 + 2;
		speedX[i] = rand() % 2 + 1;

		if (isBlowing[i]) {

			windParticles[i].y += speedY[i] * gravityReverse;
			windParticles[i].x += speedX[i];
		}
	}
	for (int i = 0; i < MAXPARTICLES; i++) {
		if (windParticles[i].y >= 800 || windParticles[i].y <= -80 || windParticles[i].x <= -80 ||
		    windParticles[i].x >= 1360) {
			isBlowing[i] = false;
		}
	}


}

void Wind::GravityReversed() {

	if (isGravityReversed) {
		gravityReverse = -1;
		emitter.y = 720;
	} else {
		gravityReverse = 1;
		emitter.y = 0;
	}


}

void Wind::ScrollWind() {

	if (isScrollXForwardWind) {
		for (int i = 0; i < MAXPARTICLES; i++) {
			windParticles[i].x -= scrollSpeed;
		}
	}

	if (isScrollXBackwardWind) {
		for (int i = 0; i < MAXPARTICLES; i++) {
			windParticles[i].x += scrollSpeed;
		}
	}

}

void Wind::UpdateWind() {

	//ScrollWind();
	BlowWind();

}

void Wind::DrawWind() {

		for (int i = 0; i < MAXPARTICLES; i++) {
		if (isBlowing[i]) {
			Novice::DrawEllipse(
			    (int)windParticles[i].x, (int)windParticles[i].y, radius[i], radius[i], 0.0f,
			    WHITE, kFillModeSolid);
		}
	}

}

void Wind::Draw() {

	DrawWind();

	//Novice::ScreenPrintf(0, 0, "%f", windParticles[0].y);

}
