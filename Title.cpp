#include "Title.h"

void Title::TitleInitialize() {

	title.pos.x = 0;
	title.pos.y = 0;
	title.animation = 0;
	title.frames = 0;
	title.keyPressed = false;
	title.handle = Novice::LoadTexture("./Sprites/TitleScreen.png");

}

void Title::Animation() {

	title.frames++;

	if (title.frames >= 50) {
		title.animation++;
		title.frames = 0;
	}

	if (title.animation >= 2) {
		title.animation = 0;
	}

}

void Title::KeyPressed(char* keys) {

		if (keys[DIK_SPACE]) {
		title.keyPressed = true;
		}
	

}

void Title::TitleUpdate(char* keys) {
	Animation();
	KeyPressed(keys);

}

void Title::TitleDraw() {
	Novice::DrawQuad(
	    (int)title.pos.x, (int)title.pos.y, (int)title.pos.x + 1280, (int)title.pos.y,
	    (int)title.pos.x, (int)title.pos.y + 720, (int)title.pos.x + 1280, (int)title.pos.y + 720,
	    1280 * title.animation, 0, 1280, 720, title.handle, WHITE);
	}


