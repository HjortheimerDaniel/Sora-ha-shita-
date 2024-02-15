#include "GravityButton.h"

void GravityButton::Initialize() {

	#pragma region BlockUp

	gravityUpwardsBlock[0].UL.x = 2350;
	gravityUpwardsBlock[0].UL.y = 600;
	gravityUpwardsBlock[0].UR.x = 2430;
	gravityUpwardsBlock[0].UR.y = 600;
	gravityUpwardsBlock[0].LL.x = 2350;
	gravityUpwardsBlock[0].LL.y = 700;
	gravityUpwardsBlock[0].LR.x = 2430;
	gravityUpwardsBlock[0].LR.y = 700;

	#pragma endregion

	#pragma region BlockDown

	gravityDownwardsBlock[0].UL.x = 4450;
	gravityDownwardsBlock[0].UL.y = 20;
	gravityDownwardsBlock[0].UR.x = 4530;
	gravityDownwardsBlock[0].UR.y = 20;
	gravityDownwardsBlock[0].LL.x = 4450;
	gravityDownwardsBlock[0].LL.y = 120;
	gravityDownwardsBlock[0].LR.x = 4530;
	gravityDownwardsBlock[0].LR.y = 120;

	#pragma endregion
	

	upSize = {80, 100};
	blockHandle = Novice::LoadTexture("./Sprites/GravityButton.png");
	isScrollXBackward = false;
	isScrollXForward = false;
	scrollSpeed = {0, 0};
}

void GravityButton::Initialize2() {

	#pragma region BlockUp

	gravityUpwardsBlock[0].UL.x = 490;
	gravityUpwardsBlock[0].UL.y = 350;
	gravityUpwardsBlock[0].UR.x = 540;
	gravityUpwardsBlock[0].UR.y = 350;
	gravityUpwardsBlock[0].LL.x = 490;
	gravityUpwardsBlock[0].LL.y = 400;
	gravityUpwardsBlock[0].LR.x = 540;
	gravityUpwardsBlock[0].LR.y = 400;

	gravityUpwardsBlock[1].UL.x = 900;
	gravityUpwardsBlock[1].UL.y = 350;
	gravityUpwardsBlock[1].UR.x = 950;
	gravityUpwardsBlock[1].UR.y = 350;
	gravityUpwardsBlock[1].LL.x = 900;
	gravityUpwardsBlock[1].LL.y = 400;
	gravityUpwardsBlock[1].LR.x = 950;
	gravityUpwardsBlock[1].LR.y = 400;

	gravityUpwardsBlock[2].UL.x = 1600;
	gravityUpwardsBlock[2].UL.y = 620;
	gravityUpwardsBlock[2].UR.x = 1650;
	gravityUpwardsBlock[2].UR.y = 620;
	gravityUpwardsBlock[2].LL.x = 1600;
	gravityUpwardsBlock[2].LL.y = 670;
	gravityUpwardsBlock[2].LR.x = 1650;
	gravityUpwardsBlock[2].LR.y = 670;

	gravityUpwardsBlock[3].UL.x = 3000;
	gravityUpwardsBlock[3].UL.y = 600;
	gravityUpwardsBlock[3].UR.x = 3050;
	gravityUpwardsBlock[3].UR.y = 600;
	gravityUpwardsBlock[3].LL.x = 3000;
	gravityUpwardsBlock[3].LL.y = 650;
	gravityUpwardsBlock[3].LR.x = 3050;
	gravityUpwardsBlock[3].LR.y = 650;

	gravityUpwardsBlock[4].UL.x = 3400;
	gravityUpwardsBlock[4].UL.y = 600;
	gravityUpwardsBlock[4].UR.x = 3450;
	gravityUpwardsBlock[4].UR.y = 600;
	gravityUpwardsBlock[4].LL.x = 3400;
	gravityUpwardsBlock[4].LL.y = 650;
	gravityUpwardsBlock[4].LR.x = 3450;
	gravityUpwardsBlock[4].LR.y = 650;

	gravityUpwardsBlock[5].UL.x = 3600;
	gravityUpwardsBlock[5].UL.y = 600;
	gravityUpwardsBlock[5].UR.x = 3650;
	gravityUpwardsBlock[5].UR.y = 600;
	gravityUpwardsBlock[5].LL.x = 3600;
	gravityUpwardsBlock[5].LL.y = 650;
	gravityUpwardsBlock[5].LR.x = 3650;
	gravityUpwardsBlock[5].LR.y = 650;

#pragma endregion

#pragma region BlockDown

	gravityDownwardsBlock[0].UL.x = 750;
	gravityDownwardsBlock[0].UL.y = 120;
	gravityDownwardsBlock[0].UR.x = 800;
	gravityDownwardsBlock[0].UR.y = 120;
	gravityDownwardsBlock[0].LL.x = 750;
	gravityDownwardsBlock[0].LL.y = 170;
	gravityDownwardsBlock[0].LR.x = 800;
	gravityDownwardsBlock[0].LR.y = 170;

	gravityDownwardsBlock[1].UL.x = 1850;
	gravityDownwardsBlock[1].UL.y = 200;
	gravityDownwardsBlock[1].UR.x = 1900;
	gravityDownwardsBlock[1].UR.y = 200;
	gravityDownwardsBlock[1].LL.x = 1850;
	gravityDownwardsBlock[1].LL.y = 250;
	gravityDownwardsBlock[1].LR.x = 1900;
	gravityDownwardsBlock[1].LR.y = 250;

	gravityDownwardsBlock[2].UL.x = 3000;
	gravityDownwardsBlock[2].UL.y = 100;
	gravityDownwardsBlock[2].UR.x = 3050;
	gravityDownwardsBlock[2].UR.y = 100;
	gravityDownwardsBlock[2].LL.x = 3000;
	gravityDownwardsBlock[2].LL.y = 150;
	gravityDownwardsBlock[2].LR.x = 3050;
	gravityDownwardsBlock[2].LR.y = 150;

	gravityDownwardsBlock[3].UL.x = 3200;
	gravityDownwardsBlock[3].UL.y = 400;
	gravityDownwardsBlock[3].UR.x = 3250;
	gravityDownwardsBlock[3].UR.y = 400;
	gravityDownwardsBlock[3].LL.x = 3200;
	gravityDownwardsBlock[3].LL.y = 450;
	gravityDownwardsBlock[3].LR.x = 3250;
	gravityDownwardsBlock[3].LR.y = 450;




#pragma endregion

	upSize = {50, 50};
	blockHandle = Novice::LoadTexture("./Sprites/GravityButton.png");
	isScrollXBackward = false;
	isScrollXForward = false;
	scrollSpeed = {0, 0};

}

void GravityButton::Initialize3() {

	#pragma region BlockUp

	gravityUpwardsBlock[0].UL.x = 1290;
	gravityUpwardsBlock[0].UL.y = 550;
	gravityUpwardsBlock[0].UR.x = 1340;
	gravityUpwardsBlock[0].UR.y = 550;
	gravityUpwardsBlock[0].LL.x = 1290;
	gravityUpwardsBlock[0].LL.y = 600;
	gravityUpwardsBlock[0].LR.x = 1340;
	gravityUpwardsBlock[0].LR.y = 600;

	gravityUpwardsBlock[1].UL.x = 2050;
	gravityUpwardsBlock[1].UL.y = 600;
	gravityUpwardsBlock[1].UR.x = 2100;
	gravityUpwardsBlock[1].UR.y = 600;
	gravityUpwardsBlock[1].LL.x = 2050;
	gravityUpwardsBlock[1].LL.y = 650;
	gravityUpwardsBlock[1].LR.x = 2100;
	gravityUpwardsBlock[1].LR.y = 650;
	
	gravityUpwardsBlock[2].UL.x = 2750;
	gravityUpwardsBlock[2].UL.y = 600;
	gravityUpwardsBlock[2].UR.x = 2800;
	gravityUpwardsBlock[2].UR.y = 600;
	gravityUpwardsBlock[2].LL.x = 2750;
	gravityUpwardsBlock[2].LL.y = 650;
	gravityUpwardsBlock[2].LR.x = 2800;
	gravityUpwardsBlock[2].LR.y = 650;
	
	gravityUpwardsBlock[3].UL.x = 3370;
	gravityUpwardsBlock[3].UL.y = 600;
	gravityUpwardsBlock[3].UR.x = 3420;
	gravityUpwardsBlock[3].UR.y = 600;
	gravityUpwardsBlock[3].LL.x = 3370;
	gravityUpwardsBlock[3].LL.y = 650;
	gravityUpwardsBlock[3].LR.x = 3420;
	gravityUpwardsBlock[3].LR.y = 650;
	
	//gravityUpwardsBlock[4].UL.x = 3400;
	//gravityUpwardsBlock[4].UL.y = 600;
	//gravityUpwardsBlock[4].UR.x = 3450;
	//gravityUpwardsBlock[4].UR.y = 600;
	//gravityUpwardsBlock[4].LL.x = 3400;
	//gravityUpwardsBlock[4].LL.y = 650;
	//gravityUpwardsBlock[4].LR.x = 3450;
	//gravityUpwardsBlock[4].LR.y = 650;
	//
	//gravityUpwardsBlock[5].UL.x = 3600;
	//gravityUpwardsBlock[5].UL.y = 600;
	//gravityUpwardsBlock[5].UR.x = 3650;
	//gravityUpwardsBlock[5].UR.y = 600;
	//gravityUpwardsBlock[5].LL.x = 3600;
	//gravityUpwardsBlock[5].LL.y = 650;
	//gravityUpwardsBlock[5].LR.x = 3650;
	//gravityUpwardsBlock[5].LR.y = 650;

#pragma endregion

#pragma region BlockDown

	gravityDownwardsBlock[0].UL.x = 1490;
	gravityDownwardsBlock[0].UL.y = 100;
	gravityDownwardsBlock[0].UR.x = 1540;
	gravityDownwardsBlock[0].UR.y = 100;
	gravityDownwardsBlock[0].LL.x = 1490;
	gravityDownwardsBlock[0].LL.y = 150;
	gravityDownwardsBlock[0].LR.x = 1540;
	gravityDownwardsBlock[0].LR.y = 150;

	gravityDownwardsBlock[1].UL.x = 2050;
	gravityDownwardsBlock[1].UL.y = 100;
	gravityDownwardsBlock[1].UR.x = 2100;
	gravityDownwardsBlock[1].UR.y = 100;
	gravityDownwardsBlock[1].LL.x = 2050;
	gravityDownwardsBlock[1].LL.y = 150;
	gravityDownwardsBlock[1].LR.x = 2100;
	gravityDownwardsBlock[1].LR.y = 150;

	gravityDownwardsBlock[2].UL.x = 2750;
	gravityDownwardsBlock[2].UL.y = 100;
	gravityDownwardsBlock[2].UR.x = 2800;
	gravityDownwardsBlock[2].UR.y = 100;
	gravityDownwardsBlock[2].LL.x = 2750;
	gravityDownwardsBlock[2].LL.y = 150;
	gravityDownwardsBlock[2].LR.x = 2800;
	gravityDownwardsBlock[2].LR.y = 150;

	gravityDownwardsBlock[3].UL.x = 3370;
	gravityDownwardsBlock[3].UL.y = 100;
	gravityDownwardsBlock[3].UR.x = 3420;
	gravityDownwardsBlock[3].UR.y = 100;
	gravityDownwardsBlock[3].LL.x = 3370;
	gravityDownwardsBlock[3].LL.y = 150;
	gravityDownwardsBlock[3].LR.x = 3420;
	gravityDownwardsBlock[3].LR.y = 150;

#pragma endregion

	upSize = {50, 50};
	blockHandle = Novice::LoadTexture("./Sprites/GravityButton.png");
	isScrollXBackward = false;
	isScrollXForward = false;
	scrollSpeed = {0, 0};

}

void GravityButton::ScrollButton() {
	for (int i = 0; i < MAXBLOCKS; i++) {

		if (isScrollXForward) {

			gravityUpwardsBlock[i].UL.x -= scrollSpeed.x;
			gravityUpwardsBlock[i].UR.x -= scrollSpeed.x;
			gravityUpwardsBlock[i].LL.x -= scrollSpeed.x;
			gravityUpwardsBlock[i].LR.x -= scrollSpeed.x;

			gravityDownwardsBlock[i].UL.x -= scrollSpeed.x;
			gravityDownwardsBlock[i].UR.x -= scrollSpeed.x;
			gravityDownwardsBlock[i].LL.x -= scrollSpeed.x;
			gravityDownwardsBlock[i].LR.x -= scrollSpeed.x;
		}

		if (isScrollXBackward) {

			gravityUpwardsBlock[i].UL.x += scrollSpeed.x;
			gravityUpwardsBlock[i].UR.x += scrollSpeed.x;
			gravityUpwardsBlock[i].LL.x += scrollSpeed.x;
			gravityUpwardsBlock[i].LR.x += scrollSpeed.x;

			gravityDownwardsBlock[i].UL.x += scrollSpeed.x;
			gravityDownwardsBlock[i].UR.x += scrollSpeed.x;
			gravityDownwardsBlock[i].LL.x += scrollSpeed.x;
			gravityDownwardsBlock[i].LR.x += scrollSpeed.x;
		}
	}

}

void GravityButton::Update() { 
	ScrollButton();
}

void GravityButton::Draw() {
	for (int i = 0; i < MAXBLOCKS; i++) {
		    if (gravityUpwardsBlock[i].UL.x <= 1920 && gravityUpwardsBlock[i].UL.x >= -80) {

			    Novice::DrawQuad(
			        (int)gravityUpwardsBlock[i].UL.x, (int)gravityUpwardsBlock[i].UL.y,
			        (int)gravityUpwardsBlock[i].UR.x, (int)gravityUpwardsBlock[i].UR.y,
			        (int)gravityUpwardsBlock[i].LL.x, (int)gravityUpwardsBlock[i].LL.y,
			        (int)gravityUpwardsBlock[i].LR.x, (int)gravityUpwardsBlock[i].LR.y, 0, 0, 50, 50,
			        blockHandle, RED);
		    }
		    if (gravityDownwardsBlock[i].UL.x <= 1920 && gravityDownwardsBlock[i].UL.x >= -80) {

			    Novice::DrawQuad(
			        (int)gravityDownwardsBlock[i].UL.x, (int)gravityDownwardsBlock[i].UL.y,
			        (int)gravityDownwardsBlock[i].UR.x, (int)gravityDownwardsBlock[i].UR.y,
			        (int)gravityDownwardsBlock[i].LL.x, (int)gravityDownwardsBlock[i].LL.y,
			        (int)gravityDownwardsBlock[i].LR.x, (int)gravityDownwardsBlock[i].LR.y, 50, 0, 50, 50,
			        blockHandle, BLUE);
		    }
	}
}
