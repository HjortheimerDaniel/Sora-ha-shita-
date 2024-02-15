#include "StageSelect.h"

void StageSelect::Initialize(Coins* coinss, Player* playerr) {
	coins = coinss;
	player = playerr;
	coins->Initialize();
	coins->Initialize2();
	coins->Initialize3();
	coins->InitializeCoinTaken();
	coins->InitializeCoinTaken2();
	coins->InitializeCoinTaken3();

	stageHandle[0] = Novice::LoadTexture("./Sprites/StageSelect1.png");
	stageHandle[1] = Novice::LoadTexture("./Sprites/StageSelect2.png");
	stageHandle[2] = Novice::LoadTexture("./Sprites/StageSelect3.png");
	menuAltHandle = Novice::LoadTexture("./Sprites/StageSelect3Alt.png");
	coinHandle = Novice::LoadTexture("./Sprites/CoinsStageSelect.png");
	controlsHandle = Novice::LoadTexture("./Sprites/Controls.png");
	menuHandle1 = Novice::LoadTexture("./Sprites/ControlsMenu1.png");
	menuHandle2 = Novice::LoadTexture("./Sprites/ControlsMenu2.png");
	menuHandle = menuHandle1;
	for (int i = 0; i < 3; i++) {
		stagePos[i].UL.x = 0;
		stagePos[i].UL.y = 0;
		stagePos[i].UR.x = 1280;
		stagePos[i].UR.y = 0;
		stagePos[i].LL.x = 0;
		stagePos[i].LL.y = 720;
		stagePos[i].LR.x = 1280;
		stagePos[i].LR.y = 720;
		stageAnimation[i] = 0;
	}
	coinsTaken= 0;
	coinsTaken2 = 0;
	coinsTaken3 = 0;
	coinsTakenSaved = 0;
	coinsTakenSaved2 = 0;
	coinsTakenSaved3 = 0;
	stagesClear = 0;
	animation = 0;
	altAnimation = 0;

	#pragma region CoinPos

	coinPos[0].UL.x = 60;
	coinPos[0].UL.y = 380;
	coinPos[0].UR.x = 260;
	coinPos[0].UR.y = 380;
	coinPos[0].LL.x = 60;
	coinPos[0].LL.y = 480;
	coinPos[0].LR.x = 260;
	coinPos[0].LR.y = 480;

	coinPos[1].UL.x = 385;
	coinPos[1].UL.y = 380;
	coinPos[1].UR.x = 585;
	coinPos[1].UR.y = 380;
	coinPos[1].LL.x = 385;
	coinPos[1].LL.y = 480;
	coinPos[1].LR.x = 585;
	coinPos[1].LR.y = 480;

	coinPos[2].UL.x = 710;
	coinPos[2].UL.y = 380;
	coinPos[2].UR.x = 910;
	coinPos[2].UR.y = 380;
	coinPos[2].LL.x = 710;
	coinPos[2].LL.y = 480;
	coinPos[2].LR.x = 910;
	coinPos[2].LR.y = 480;

	#pragma endregion
	
	stageFinished[0] = false;
	stageFinished[1] = false;
	stageFinished[2] = false;
	for (int i = 0; i < 3; i++) {
		stageCleared[i] = false;
	}
	isPauseMenu = false;
	isStage3Reached = false;
	cooldown = 0;
	voiceHandle[0] = -1;
	titleBGM = Novice::LoadAudio("./Audio/Title.mp3");

}

void StageSelect::StageAnimation(char* keys, char* preKeys) {


	if (keys[DIK_D] && !preKeys[DIK_D]) {
		stageAnimation[animation]++;
	}

	if (keys[DIK_A] && !preKeys[DIK_A]) {
		stageAnimation[animation]--;
	}

	if (stageAnimation[animation] >= 3) {
		stageAnimation[animation] = 0;
	}
	if (stageAnimation[animation] <= -1) {
		stageAnimation[animation] = 2;
	}

	if (coinsTakenSaved3 == 3 && coinsTakenSaved2 == 3 && coinsTakenSaved == 3) {
		if (keys[DIK_D] && !preKeys[DIK_D]) {
			altAnimation++;
		}

		if (keys[DIK_A] && !preKeys[DIK_A]) {
			altAnimation--;
		}

		if (altAnimation >= 3) {
			altAnimation = 0;
		}
		if (altAnimation <= -1) {
			altAnimation = 2;
		}
	}

}

void StageSelect::ControlsMenu(char* keys, char* preKeys) {

	if (cooldown >= 1) {
		cooldown++;
	}

	if (cooldown >= 5) {
		cooldown = 0;
	}

	if (keys[DIK_H] && !preKeys[DIK_H] && !isPauseMenu && cooldown == 0) {
		isPauseMenu = true;
		cooldown = 1;
	}
	if (keys[DIK_H] && !preKeys[DIK_H] && isPauseMenu && cooldown == 0) {
		isPauseMenu = false;
		cooldown = 1;
	}

	if (isStage3Reached) {
		menuHandle = menuHandle2;
	}
}


void StageSelect::Update(char* keys, char* preKeys) {

		StageAnimation(keys, preKeys);
		CoinsTaken();
		StagesCleared();
		ControlsMenu(keys, preKeys);
	   
}

void StageSelect::Update2() {
		CoinsTaken2();
		StagesCleared2();
}

void StageSelect::Update3() {
	
		CoinsTaken3();
		StagesCleared3();

}

void StageSelect::CoinsTaken() {

	if (coins->GetHowManyCoinsTaken() == 0) {
		coinsTaken = 0;
	}

		if (coinsTaken < coins->GetHowManyCoinsTaken()) {
			coinsTaken = coins->GetHowManyCoinsTaken();
		}

		if (player->GetPlayerDead()) {
			coinsTaken = 0;
		}

		if (stageFinished[0] && coinsTakenSaved < coinsTaken) {
			coinsTakenSaved = coinsTaken;
		}

	

}

//FIX COINS ON STAGESELECT


void StageSelect::CoinsTaken2() {

		if (coins->GetHowManyCoinsTaken2() == 0) {
			coinsTaken2 = 0;
		}

		if (coinsTaken2 < coins->GetHowManyCoinsTaken2()) {
			coinsTaken2 = coins->GetHowManyCoinsTaken2();
		}

		if (player->GetPlayerDead() == true || player->GetPlayerSpiked() == true) {
			coins->SetHowManyCoinsTaken2(0);
			coinsTaken2 = 0;
		}

		if (stageFinished[1] && coinsTakenSaved2 < coinsTaken2) {
			coinsTakenSaved2 = coinsTaken2;
		}
	 

}

void StageSelect::CoinsTaken3() {

	if (coins->GetHowManyCoinsTaken3() == 0) {
		    coinsTaken3 = 0;
	    }

	    if (coinsTaken3 < coins->GetHowManyCoinsTaken3()) {
		    coinsTaken3 = coins->GetHowManyCoinsTaken3();
	    }

	    if (player->GetPlayerDead() == true || player->GetPlayerSpiked() == true) {
		    coins->SetHowManyCoinsTaken3(0);
		    coinsTaken3 = 0;
	    }

	    if (stageFinished[2] && coinsTakenSaved3 < coinsTaken3) {
		    coinsTakenSaved3 = coinsTaken3;
	    }

}

void StageSelect::DrawCoins() {
	 

		Novice::DrawQuad(
		    (int)coinPos[0].UL.x, (int)coinPos[0].UL.y, (int)coinPos[0].UR.x, (int)coinPos[0].UR.y,
		    (int)coinPos[0].LL.x, (int)coinPos[0].LL.y, (int)coinPos[0].LR.x, (int)coinPos[0].LR.y,
		    200 * coinsTakenSaved, 0, 200, 100, coinHandle, WHITE);

		Novice::DrawQuad(
		    (int)coinPos[1].UL.x, (int)coinPos[1].UL.y, (int)coinPos[1].UR.x, (int)coinPos[1].UR.y,
		    (int)coinPos[1].LL.x, (int)coinPos[1].LL.y, (int)coinPos[1].LR.x, (int)coinPos[1].LR.y,
		    200 * coinsTakenSaved2, 0, 200, 100, coinHandle, WHITE);

			Novice::DrawQuad(
	        (int)coinPos[2].UL.x, (int)coinPos[2].UL.y, (int)coinPos[2].UR.x, (int)coinPos[2].UR.y,
	        (int)coinPos[2].LL.x, (int)coinPos[2].LL.y, (int)coinPos[2].LR.x, (int)coinPos[2].LR.y,
	        200 * coinsTakenSaved3, 0, 200, 100, coinHandle, WHITE);
	 


}

void StageSelect::StagesCleared() {

	if (stageFinished[0]) {
		stageCleared[0] = true;
		stageFinished[0] = false;
	}

	if (stageCleared[0]) {
		stagesClear = 1;
	}
	//Novice::ScreenPrintf(0, 60, "%d", stagesClear);



}

void StageSelect::StagesCleared2() {
	if (stageFinished[1]) {
		stageCleared[1] = true;
		stageFinished[1] = false;
	}
	if (stageCleared[1]) {
		stagesClear = 2;
	}

}

void StageSelect::StagesCleared3() {

	if (stageFinished[2]) {
		stageCleared[2] = true;
		stageFinished[2] = false;
	}
	

}

void StageSelect::DrawControls() {

	Novice::DrawSprite(950, 350, controlsHandle, 1, 1, 0.0f, WHITE);

}

void StageSelect::DrawPauseMenu() {

	Novice::DrawSprite(0, 0, menuHandle, 1, 1, 0.0f, WHITE);

}

void StageSelect::DrawDaniel() {

	Novice::DrawQuad(
	    (int)stagePos[stagesClear].UL.x, (int)stagePos[stagesClear].UL.y,
	    (int)stagePos[stagesClear].UR.x, (int)stagePos[stagesClear].UR.y,
	    (int)stagePos[stagesClear].LL.x, (int)stagePos[stagesClear].LL.y,
	    (int)stagePos[stagesClear].LR.x, (int)stagePos[stagesClear].LR.y,
	    1280 * altAnimation, 0, 1280, 720, menuAltHandle, WHITE);

}

void StageSelect::Draw() {
	if (!isPauseMenu) {
		
			Novice::DrawQuad(
			    (int)stagePos[stagesClear].UL.x, (int)stagePos[stagesClear].UL.y,
			    (int)stagePos[stagesClear].UR.x, (int)stagePos[stagesClear].UR.y,
			    (int)stagePos[stagesClear].LL.x, (int)stagePos[stagesClear].LL.y,
			    (int)stagePos[stagesClear].LR.x, (int)stagePos[stagesClear].LR.y,
			    1280 * stageAnimation[animation], 0, 1280, 720, stageHandle[stagesClear], WHITE);
		
		if(coinsTakenSaved3 == 3 && coinsTakenSaved2 == 3 && coinsTakenSaved == 3)  {
			DrawDaniel();
		}
		
		DrawCoins();
		DrawControls();
	}

	if (isPauseMenu) {

		DrawPauseMenu();
	}


	//Novice::ScreenPrintf(0, 20, "%d", coinsTaken);
	//Novice::ScreenPrintf(0, 40, "%d", coins->GetHowManyCoinsTaken());

}




		
