#include "Background.h"



void Background::BackgroundInitialize() {

	for (int i = 0; i < MAXBACKGROUNDS; i++) {
		backgroundPos[i].x = 1280 * (float)i;
		backgroundPos[i].y = 0;

	}

	#pragma region Handles

	handle[0] = Novice::LoadTexture("./Sprites/background1.png"); 
	handle[1] = Novice::LoadTexture("./Sprites/background2.png"); 
	handle[2] = Novice::LoadTexture("./Sprites/background3.png"); 
	handle[3] = Novice::LoadTexture("./Sprites/background4.png"); 
	handle[4] = Novice::LoadTexture("./Sprites/background5.png"); 
	
	#pragma endregion

	BackgroundisScrollXBackward = false;
	BackgroundisScrollXForward = false;
	scrollSpeed = {0, 0};
	Backgroundcolor = WHITE;
	for (int i = 0; i < 2; i++) {
		reversed[i] = 0;
		//isReversed[i] = false;
	}
	reverseSize = 1;
	

}

void Background::BackgroundInitialize2() {

	for (int i = 0; i < MAXBACKGROUNDS2; i++) {
		backgroundPos2[i].x = 1280 * (float)i;
		backgroundPos2[i].y = 0;
	}

#pragma region Handles

	handle2[0] = Novice::LoadTexture("./Sprites/background21.png");
	handle2[1] = Novice::LoadTexture("./Sprites/background22.png");
	handle2[2] = Novice::LoadTexture("./Sprites/background23.png");
	handle2[3] = Novice::LoadTexture("./Sprites/background2.png");
	handle2[4] = Novice::LoadTexture("./Sprites/background1.png");

#pragma endregion

	BackgroundisScrollXBackward = false;
	BackgroundisScrollXForward = false;
	scrollSpeed = {0, 0};
	Backgroundcolor = WHITE;
	for (int i = 0; i < 2; i++) {
		reversed[i] = 0;
		// isReversed[i] = false;
	}
	reverseSize = 1;

}

void Background::BackgroundInitialize3() {

		for (int i = 0; i < MAXBACKGROUNDS2; i++) {
		backgroundPos3[i].x = 1280 * (float)i;
		backgroundPos3[i].y = 0;
	}

#pragma region Handles

	handle3[0] = Novice::LoadTexture("./Sprites/background2.png");
	handle3[1] = Novice::LoadTexture("./Sprites/background21.png");
	handle3[2] = Novice::LoadTexture("./Sprites/background4.png");
	handle3[3] = Novice::LoadTexture("./Sprites/background5.png");
	handle3[4] = Novice::LoadTexture("./Sprites/background1.png");

#pragma endregion

	BackgroundisScrollXBackward = false;
	BackgroundisScrollXForward = false;
	scrollSpeed = {0, 0};
	Backgroundcolor = WHITE;
	for (int i = 0; i < 2; i++) {
		reversed[i] = 0;
		// isReversed[i] = false;
	}
	reverseSize = 1;

}

void Background::Reverse() {

	/*if (isReversed[0]) {
		reversed[0] = -1;
	} else {
		reversed[0] = 1;
	}*/

}

void Background::BackgroundScroll() {
	for (int i = 0; i < MAXBACKGROUNDS; i++) {

		if (BackgroundisScrollXForward) {

			backgroundPos[i].x -= scrollSpeed.x;
		}

		if (BackgroundisScrollXBackward) {

			backgroundPos[i].x += scrollSpeed.x;
		}
	}
}

void Background::BackgroundScroll2() {

	for (int i = 0; i < MAXBACKGROUNDS2; i++) {

		if (BackgroundisScrollXForward) {

			backgroundPos2[i].x -= scrollSpeed.x;
		}

		if (BackgroundisScrollXBackward) {

			backgroundPos2[i].x += scrollSpeed.x;
		}
	}

}

void Background::BackgroundScroll3() {

	for (int i = 0; i < MAXBACKGROUNDS2; i++) {

		if (BackgroundisScrollXForward) {

			backgroundPos3[i].x -= scrollSpeed.x;
		}

		if (BackgroundisScrollXBackward) {

			backgroundPos3[i].x += scrollSpeed.x;
		}
	}

}

void Background::BackgroundUpdate() {

	BackgroundScroll();

}

void Background::BackgroundUpdate2() {

	BackgroundScroll2();

}

void Background::BackgroundUpdate3() {

	BackgroundScroll3();

}

void Background::BackgroundDraw() {

	for (int i = 0; i < MAXBACKGROUNDS; i++) {

		Novice::DrawSprite(
		    (int)backgroundPos[i].x /*+ (int)reversed[0]*/,
		    (int)backgroundPos[i].y + (int)reversed[1],
		    (int)handle[i], 1, reverseSize, 0.0f, Backgroundcolor);
	}

	

}

void Background::BackgroundDraw2() {

		for (int i = 0; i < MAXBACKGROUNDS; i++) {
			Novice::DrawSprite((int)backgroundPos2[i].x,(int)backgroundPos2[i].y + (int)reversed[1], (int)handle2[i], 1, reverseSize, 0.0f, Backgroundcolor);
	}

}

void Background::BackgroundDraw3() {

	for (int i = 0; i < MAXBACKGROUNDS; i++) {
		    Novice::DrawSprite(
		        (int)backgroundPos3[i].x, (int)backgroundPos3[i].y + (int)reversed[1],
		        (int)handle3[i], 1, reverseSize, 0.0f, Backgroundcolor);
	}

}
