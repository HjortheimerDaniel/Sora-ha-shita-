#include "Floor.h"

void Floor::Initialize() {

	#pragma region LinePos

	lineStart[0].x = 0;
	lineStart[0].y = 500;
	lineEnd[0].x = 800;
	lineEnd[0].y = 500;
	lineStart[1].x = 900;
	lineStart[1].y = 500;
	lineEnd[1].x = 1200;
	lineEnd[1].y = 500;
	lineStart[2].x = 1300;
	lineStart[2].y = 400;
	lineEnd[2].x = 1500;
	lineEnd[2].y = 400;
	lineStart[3].x = 1600;
	lineStart[3].y = 300;
	lineEnd[3].x = 1800;
	lineEnd[3].y = 300;
	lineStart[4].x = 1900;
	lineStart[4].y = 200;
	lineEnd[4].x = 2100;
	lineEnd[4].y = 200;
	lineStart[5].x = 2300;
	lineStart[5].y = 30;
	lineEnd[5].x = 3100;
	lineEnd[5].y = 30;

	lineStart[6].x = 3200;
	lineStart[6].y = 130;
	lineEnd[6].x = 3400;
	lineEnd[6].y = 130;
	lineStart[7].x = 3500;
	lineStart[7].y = 230;
	lineEnd[7].x = 3700;
	lineEnd[7].y = 230;
	lineStart[8].x = 3800;
	lineStart[8].y = 330;
	lineEnd[8].x = 4000;
	lineEnd[8].y = 330;
	lineStart[9].x = 4100;
	lineStart[9].y = 430;
	lineEnd[9].x = 4300;
	lineEnd[9].y = 430;
	lineStart[10].x = 4500;
	lineStart[10].y = 600;
	lineEnd[10].x = 5500;
	lineEnd[10].y = 600;
	sizeHandleStage1[0] = Novice::LoadTexture("./Sprites/platform200.png");
	sizeHandleStage1[1] = Novice::LoadTexture("./Sprites/platformMetal.png");
	sizeHandleStage1[2] = Novice::LoadTexture("./Sprites/platform800.png");
	sizeHandleStage1[3] = Novice::LoadTexture("./Sprites/platformMetalLong.png");
	
	//FIX HANDLES FOR THE GROUND

	#pragma endregion

	#pragma region LineSize

	for (int i = 0; i < MAXLines; i++) {
		lineSize[i].x = lineEnd[i].x - lineStart[i].x;
		lineSize[i].y = 1;
	}

	#pragma endregion

	isScrollXForward = false;
	isScrollXBackward = false;
	scrollSpeed = 5;
}

void Floor::Initialize2() {

	#pragma region LinePos

	lineStart[0].x = 0;
	lineStart[0].y = 500;
	lineEnd[0].x = 1140;
	lineEnd[0].y = 500;
	lineStart[1].x = 0;
	lineStart[1].y = 30;
	lineEnd[1].x = 1300;
	lineEnd[1].y = 30;
	lineStart[2].x = 1400;
	lineStart[2].y = 100;
	lineEnd[2].x = 1700;
	lineEnd[2].y = 100;
	lineStart[3].x = 1700;
	lineStart[3].y = 600;
	lineEnd[3].x = 2000;
	lineEnd[3].y = 600;
	lineStart[4].x = 2050;
	lineStart[4].y = 500;
	lineEnd[4].x = 2350;
	lineEnd[4].y = 500;
	lineStart[5].x = 2550;
	lineStart[5].y = 500;
	lineEnd[5].x = 2850;
	lineEnd[5].y = 500;
	lineStart[6].x = 3200;
	lineStart[6].y = 230;
	lineEnd[6].x = 3500;
	lineEnd[6].y = 230;
	lineStart[7].x = 3850;
	lineStart[7].y = 530;
	lineEnd[7].x = 4150;
	lineEnd[7].y = 530;
	lineStart[8].x = 4600;
	lineStart[8].y = 30;
	lineEnd[8].x = 5600;
	lineEnd[8].y = 30;

	#pragma region Handle

	sizeHandleStage2[0] = Novice::LoadTexture("./Sprites/platform1140.png");
	sizeHandleStage2[1] = Novice::LoadTexture("./Sprites/platform1300.png");
	sizeHandleStage2[2] = Novice::LoadTexture("./Sprites/platformMetal.png");
	sizeHandleStage2[3] = Novice::LoadTexture("./Sprites/platformMetalLong.png");

	#pragma endregion

#pragma endregion

#pragma region LineSize

	for (int i = 0; i < MAXLines; i++) {
		lineSize[i].x = lineEnd[i].x - lineStart[i].x;
		lineSize[i].y = 1;
	}

#pragma endregion

	isScrollXForward = false;
	isScrollXBackward = false;
	scrollSpeed = 5;

	#pragma region MovingPlatforms

	goLeft[0] = false;
	goLeft[1] = true;
	goLeft[2] = false;
	goRight[0] = true;
	goRight[1] = false;
	goRight[2] = true;
	movingPlatformStart[0].x = 2550;
	movingPlatformStart[0].y = 500;
	movingPlatformEnd[0].x = 2850;
	movingPlatformEnd[0].y = 500;
	movingPlatformStart[1].x = 3200;
	movingPlatformStart[1].y = 500;
	movingPlatformEnd[1].x = 3500;
	movingPlatformEnd[1].y = 500;
	movingPlatformStart[2].x = 3850;
	movingPlatformStart[2].y = 500;
	movingPlatformEnd[2].x = 4150;
	movingPlatformEnd[2].y = 500;
	movingPlatformSize = 300;
	platformSpeed = 2;
	directionTimer = 0;
	lineMovement = 0;
	amplitude = 150.0f;
	amplitude2 = -150.0f;
	theta = 0.0f;

	
	#pragma endregion
}

void Floor::Initialize3() {

	#pragma region LinePos

	lineStart[0].x = 0;
	lineStart[0].y = 500;
	lineEnd[0].x = 700;
	lineEnd[0].y = 500;
	lineStart[1].x = 30;
	lineStart[1].y = 660; 
	lineEnd[1].x = 330;
	lineEnd[1].y = 660;
	lineStart[2].x = 700;
	lineStart[2].y = 660;
	lineEnd[2].x = 1000;
	lineEnd[2].y = 660;
	lineStart[3].x = 1500;
	lineStart[3].y = 300;
	lineEnd[3].x = 1800;
	lineEnd[3].y = 300;
	lineStart[4].x = 3500;
	lineStart[4].y = 30;
	lineEnd[4].x = 4500;
	lineEnd[4].y = 30;
	lineStart[5].x = 3500;
	lineStart[5].y = 700;
	lineEnd[5].x = 4500;
	lineEnd[5].y = 700;
	lineStart[6].x = 3700;
	lineStart[6].y = 300;
	lineEnd[6].x = 4000;
	lineEnd[6].y = 300;
	lineStart[7].x = 3700;
	lineStart[7].y = 480;
	lineEnd[7].x = 4000;
	lineEnd[7].y = 480;
	//lineStart[8].x = 4600;
	//lineStart[8].y = 30;
	//lineEnd[8].x = 5500;
	//lineEnd[8].y = 30;
	// lineStart[9].x = 4000;
	// lineStart[9].y = 430;
	// lineEnd[9].x = 4200;
	// lineEnd[9].y = 430;
	// lineStart[10].x = 4400;
	// lineStart[10].y = 600;
	// lineEnd[10].x = 5500;
	// lineEnd[10].y = 600;

	sizeHandle[0] = Novice::LoadTexture("./Sprites/platformMetal.png");
	sizeHandle[1] = Novice::LoadTexture("./Sprites/platformMetalMedium.png");
	sizeHandle[2] = Novice::LoadTexture("./Sprites/platformMetalLong.png");
	handle = Novice::LoadTexture("./Sprites/platformMetal.png");

#pragma endregion

#pragma region LineSize

	for (int i = 0; i < MAXLines; i++) {
		lineSize[i].x = lineEnd[i].x - lineStart[i].x;
		lineSize[i].y = 1;
	}

#pragma endregion

	isScrollXForward = false;
	isScrollXBackward = false;
	scrollSpeed = 5;

}

void Floor::ScrollFloor() {

	if (isScrollXForward) {
		for (int i = 0; i < MAXLines; i++) {
			lineEnd[i].x -= scrollSpeed;
			lineStart[i].x -= scrollSpeed;
		}
		for (int i = 0; i < MAXMovingLines; i++) {
			movingPlatformEnd[i].x-= scrollSpeed;
			movingPlatformStart[i].x -= scrollSpeed;
		}
	}

	if (isScrollXBackward) {
		for (int i = 0; i < MAXLines; i++) {
			lineEnd[i].x += scrollSpeed;
			lineStart[i].x += scrollSpeed;
		}
		for (int i = 0; i < MAXMovingLines; i++) {
			movingPlatformEnd[i].x += scrollSpeed;
			movingPlatformStart[i].x += scrollSpeed;
		}
	}

}

//ADD SCROLL TO THE MOVING PLATFORMS

void Floor::MovingPlatforms() {
	
	theta += float(M_PI) / 250.0f;

	lineStart[5].x = cosf(theta) * amplitude + movingPlatformStart[0].x;
	lineEnd[5].x = cosf(theta) * amplitude + movingPlatformEnd[0].x; 
	lineStart[6].x = cosf(theta) * amplitude2 + movingPlatformStart[1].x;
	lineEnd[6].x = cosf(theta) * amplitude2 + movingPlatformEnd[1].x;
	lineStart[7].x = cosf(theta) * amplitude + movingPlatformStart[2].x;
	lineEnd[7].x = cosf(theta) * amplitude + movingPlatformEnd[2].x;

}

void Floor::Sprites() {


}

void Floor::Update() { 
	ScrollFloor(); }

void Floor::Update2() {
	ScrollFloor();
	MovingPlatforms();
}

void Floor::Update3() {
	Sprites();
	ScrollFloor();
}


void Floor::Draw() { 
	/*for (int i = 0; i < MAXLines; i++) {
		if (lineStart[i].x >= lineSize[i].x *-1 && lineEnd[i].x >= 0) {

			Novice::DrawLine(
			    (int)lineStart[i].x , (int)lineStart[i].y, (int)lineEnd[i].x, (int)lineEnd[i].y,
			    RED);
		}
		
	}*/
	if (lineStart[0].x >= lineSize[0].x * -1 && lineEnd[0].x >= 0) {
		Novice::DrawSprite(
		    (int)lineStart[0].x, (int)lineStart[0].y, sizeHandleStage1[2], 1, 1, 0.0f, WHITE);
	}
	if (lineStart[5].x >= lineSize[5].x * -1 && lineEnd[5].x >= 0) {
		Novice::DrawSprite(
		    (int)lineStart[5].x, (int)lineStart[5].y, sizeHandleStage1[2], 1, 1, 0.0f, WHITE);
	}
	if (lineStart[1].x >= lineSize[1].x * -1 && lineEnd[1].x >= 0) {
		Novice::DrawSprite(
		    (int)lineStart[1].x, (int)lineStart[1].y, sizeHandleStage1[1], 1, 1, 0.0f, WHITE);
	}
	for (int i = 2; i < 5; i++) {
		if (lineStart[i].x >= lineSize[i].x * -1 && lineEnd[i].x >= 0) {
			Novice::DrawSprite(
			    (int)lineStart[i].x, (int)lineStart[i].y, sizeHandleStage1[0], 1, 1, 0.0f, WHITE);
		}
	}
	for (int i = 6; i < 10; i++) {
		if (lineStart[i].x >= lineSize[i].x * -1 && lineEnd[i].x >= 0) {
			Novice::DrawSprite(
			    (int)lineStart[i].x, (int)lineStart[i].y, sizeHandleStage1[0], 1, 1, 0.0f, WHITE);
		}
	}
	if (lineStart[10].x >= lineSize[10].x * -1 && lineEnd[10].x >= 0) {
		Novice::DrawSprite(
		    (int)lineStart[10].x, (int)lineStart[10].y, sizeHandleStage1[3], 1, 1, 0.0f, WHITE);
	}
	

}

void Floor::Draw2() {

	/*for (int i = 0; i < MAXLines; i++) {
		if (lineStart[i].x >= lineSize[i].x * -1 && lineEnd[i].x >= 0) {

			Novice::DrawLine(
			    (int)lineStart[i].x, (int)lineStart[i].y, (int)lineEnd[i].x, (int)lineEnd[i].y,
			    RED);
		}
	}*/

	for (int i = 0; i < 2; i++) {
		if (lineStart[i].x >= lineSize[i].x * -1 && lineEnd[i].x >= 0) {
			Novice::DrawSprite(
			    (int)lineStart[i].x, (int)lineStart[i].y, sizeHandleStage2[i], 1, 1, 0.0f, WHITE);
		}
	}

	
	for (int i = 2; i < 8; i++) {
		if (lineStart[i].x >= lineSize[i].x * -1 && lineEnd[i].x >= 0) {
			Novice::DrawSprite(
			    (int)lineStart[i].x, (int)lineStart[i].y, sizeHandleStage2[2], 1, 1, 0.0f, WHITE);
		}
	}
	if (lineStart[8].x >= lineSize[8].x * -1 && lineEnd[8].x >= 0) {
		Novice::DrawSprite(
		    (int)lineStart[8].x, (int)lineStart[8].y, sizeHandleStage2[3], 1, 1, 0.0f, WHITE);
	}

	




	//Novice::ScreenPrintf(0, 100, "%f", lineStart[6].x);
	//Novice::ScreenPrintf(0, 120, "%f", lineStart[5].x);
	
}

void Floor::Draw3() {

	/*for (int i = 0; i < MAXLines; i++) {
		if (lineStart[i].x >= lineSize[i].x * -1 && lineEnd[i].x >= 0) {

			Novice::DrawLine(
			    (int)lineStart[i].x, (int)lineStart[i].y, (int)lineEnd[i].x, (int)lineEnd[i].y,
			    RED);
		}
	}*/

	if (lineStart[0].x >= lineSize[0].x * -1 && lineEnd[0].x >= 0) {
		Novice::DrawSprite(
		    (int)lineStart[0].x, (int)lineStart[0].y, sizeHandle[1], 1, 1, 0.0f, WHITE);
	}

	for (int i = 1; i < 4; i++) {
		if (lineStart[i].x >= lineSize[i].x * -1 && lineEnd[i].x >= 0) {
			Novice::DrawSprite(
			    (int)lineStart[i].x, (int)lineStart[i].y, sizeHandle[0], 1, 1, 0.0f, WHITE);
		}
		
	}

		for (int i = 4; i < 6; i++) {
		if (lineStart[i].x >= lineSize[i].x * -1 && lineEnd[i].x >= 0) {
			Novice::DrawSprite(
			    (int)lineStart[i].x, (int)lineStart[i].y, sizeHandle[2], 1, 1, 0.0f, WHITE);
		}
	}

	for (int i = 6; i < 8; i++) {
		if (lineStart[i].x >= lineSize[i].x * -1 && lineEnd[i].x >= 0) {
			Novice::DrawSprite(
			    (int)lineStart[i].x, (int)lineStart[i].y, sizeHandle[0], 1, 1, 0.0f, WHITE);
		}
	}

}
