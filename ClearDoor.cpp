#include "ClearDoor.h"

void StageClear::Initialize() {

	finishPos = {
		5400, 500,
		5480, 500,
		5400, 600,
		5480, 600
	};
	finishSize = {80, 100};
	scrollSpeed = {0, 0};
	clearHandle = Novice::LoadTexture("./Sprites/Flag.png");
	isScrollXBackward = false;
	isScrollXForward = false;
	stageOnScreen = false;
	isReversed = false;
}

void StageClear::Initialize2() {

	finishPos = {5000, 32, 5080, 32, 5000, 132, 5080, 132};
	finishSize = {80, 100};
	scrollSpeed = {0, 0};
	clearHandle = Novice::LoadTexture("./Sprites/Flag.png");
	isScrollXBackward = false;
	isScrollXForward = false;
	stageOnScreen = false;
	isReversed = true;

}

void StageClear::Initialize3() {

	finishPos = {4400, 600, 4480, 600, 4400, 700, 4480, 700};
	finishSize = {80, 100};
	scrollSpeed = {0, 0};
	clearHandle = Novice::LoadTexture("./Sprites/Flag.png");
	isScrollXBackward = false;
	isScrollXForward = false;
	stageOnScreen = false;
	isReversed = false;

}

void StageClear::Scroll() {

	if (isScrollXForward) {

		finishPos.UL.x -= scrollSpeed.x;
		finishPos.UR.x -= scrollSpeed.x;
		finishPos.LL.x -= scrollSpeed.x;
		finishPos.LR.x -= scrollSpeed.x;
	}

	if (isScrollXBackward) {

		finishPos.UL.x += scrollSpeed.x;
		finishPos.UR.x += scrollSpeed.x;
		finishPos.LL.x += scrollSpeed.x;
		finishPos.LR.x += scrollSpeed.x;
	}

	
}

void StageClear::Update() { 
	Scroll();
}

void StageClear::Draw() {
	if (!isReversed) {

		Novice::DrawQuad(
		    (int)finishPos.UL.x, (int)finishPos.UL.y, (int)finishPos.UR.x, (int)finishPos.UR.y,
		    (int)finishPos.LL.x, (int)finishPos.LL.y, (int)finishPos.LR.x, (int)finishPos.LR.y, 0,
		    0, 80, 100, clearHandle, WHITE);
	}

	if (isReversed) {

		Novice::DrawQuad(
		    (int)finishPos.UL.x, (int)finishPos.UL.y +100, (int)finishPos.UR.x, (int)finishPos.UR.y + 100,
		    (int)finishPos.LL.x, (int)finishPos.LL.y - 100, (int)finishPos.LR.x, (int)finishPos.LR.y - 100, 0,
		    0, 80, 100, clearHandle, WHITE);
	}

}
