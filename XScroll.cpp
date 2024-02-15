#include "XScroll.h"
#include "Novice.h"

void XScroll::Initialize() {

	scroll = {0, 0}; 
	playerPos = {200, 400};

	
}

void XScroll::Update(char* keys, char* preKeys) {

	CameraScroll(keys, preKeys);
}

void XScroll::CameraScroll(char* keys, char* preKeys) {

	if (keys[DIK_D] && preKeys[DIK_D] && playerPos.x <= 800) {
		playerPos.x += 5;
	}

	if (keys[DIK_A] && preKeys[DIK_A] && playerPos.x >= 0) {
		playerPos.x -= 5;
	}

	if (keys[DIK_D] && preKeys[DIK_D] && playerPos.x >= 800) {
		scroll.x += 5;
	}

	if (keys[DIK_A] && preKeys[DIK_A] && playerPos.x <= 200 && scroll.x >= 1) {
		scroll.x -= 5;
	}

	if (keys[DIK_A] && preKeys[DIK_A] && scroll.x != 0 && playerPos.x <= 200) {
		playerPos.x += 5;
	}


	

}
