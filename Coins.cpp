#include "Coins.h"

void Coins::InitializeCoinTaken() {

	for (int i = 0; i < MAXCOINS; i++) {
		howManyCoinsTaken = 0;
	}

}

void Coins::InitializeCoinTaken2() {

	for (int i = 0; i < MAXCOINS; i++) {
		howManyCoinsTaken2 = 0;
	}

}

void Coins::InitializeCoinTaken3() {

	for (int i = 0; i < MAXCOINS; i++) {
		howManyCoinsTaken3 = 0;
	}
}

void Coins::Initialize() {

	#pragma region CoinPos

	coins[0].UL.x = 30;
	coins[0].UL.y = 320;
	coins[0].UR.x = 60;
	coins[0].UR.y = 320;
	coins[0].LL.x = 30;
	coins[0].LL.y = 350;
	coins[0].LR.x = 60;
	coins[0].LR.y = 350;

	coins[1].UL.x = 1700;
	coins[1].UL.y = 310;
	coins[1].UR.x = 1725;
	coins[1].UR.y = 310;
	coins[1].LL.x = 1700;
	coins[1].LL.y = 340;
	coins[1].LR.x = 1725;
	coins[1].LR.y = 340;

	coins[2].UL.x = 3880;
	coins[2].UL.y = 290;
	coins[2].UR.x = 3905;
	coins[2].UR.y = 290;
	coins[2].LL.x = 3880;
	coins[2].LL.y = 320;
	coins[2].LR.x = 3905;
	coins[2].LR.y = 320;



	#pragma endregion

	isScrollXBackward = false;
	isScrollXForward = false;

	scrollSpeed = {0, 0};
	coinHandle = Novice::LoadTexture("./Sprites/Coin.png");
	displayCoinsScoreHandle = Novice::LoadTexture("./Sprites/Score.png");
	coinSize = {30, 30};
	for (int i = 0; i < MAXCOINS; i++) {
		coinTaken[i] = false;
		coinFrames[i] = 0;
		coinAnimation[i] = 0;
		displayCoinsAnimation[i] = 0;
	}
	displayCoinsScore.UL.x = 1110;
	displayCoinsScore.UL.y = 10;
	displayCoinsScore.UR.x = 1210;
	displayCoinsScore.UR.y = 10;
	displayCoinsScore.LL.x = 1110;
	displayCoinsScore.LL.y = 40;
	displayCoinsScore.LR.x = 1210;
	displayCoinsScore.LR.y = 40;
	

	displayCoin.UL.x = 1230;
	displayCoin.UL.y = 10;
	displayCoin.UR.x = 1260;
	displayCoin.UR.y = 10;
	displayCoin.LL.x = 1230;
	displayCoin.LL.y = 40;
	displayCoin.LR.x = 1260;
	displayCoin.LR.y = 40;
	displayCoinAnimation = 0;
	displayCoinFrames = 0;
	
	

}

void Coins::Initialize2() {

	#pragma region CoinPos

	/*coins2[0].UL.x = 100;
	coins2[0].UL.y = 400;
	coins2[0].UR.x = 130;
	coins2[0].UR.y = 400;
	coins2[0].LL.x = 100;
	coins2[0].LL.y = 430;
	coins2[0].LR.x = 130;
	coins2[0].LR.y = 430;*/

	coins2[0].UL.x = 860;
	coins2[0].UL.y = 220;
	coins2[0].UR.x = 890;
	coins2[0].UR.y = 220;
	coins2[0].LL.x = 860;
	coins2[0].LL.y = 250;
	coins2[0].LR.x = 890;
	coins2[0].LR.y = 250;

	coins2[1].UL.x = 1930;
	coins2[1].UL.y = 120;
	coins2[1].UR.x = 1960;
	coins2[1].UR.y = 120;
	coins2[1].LL.x = 1930;
	coins2[1].LL.y = 150;
	coins2[1].LR.x = 1960;
	coins2[1].LR.y = 150;

	coins2[2].UL.x = 3410;
	coins2[2].UL.y = 680;
	coins2[2].UR.x = 3440;
	coins2[2].UR.y = 680;
	coins2[2].LL.x = 3410;
	coins2[2].LL.y = 710;
	coins2[2].LR.x = 3440;
	coins2[2].LR.y = 710;

#pragma endregion

	isScrollXBackward = false;
	isScrollXForward = false;

	scrollSpeed = {0, 0};
	coinHandle = Novice::LoadTexture("./Sprites/Coin.png");
	displayCoinsScoreHandle = Novice::LoadTexture("./Sprites/Score.png");
	coinSize = {30, 30};
	for (int i = 0; i < MAXCOINS; i++) {
		coinTaken2[i] = false;
		coinFrames[i] = 0;
		coinAnimation[i] = 0;
		displayCoinsAnimation2[i] = 0;
	}
	displayCoinsScore.UL.x = 1110;
	displayCoinsScore.UL.y = 10;
	displayCoinsScore.UR.x = 1210;
	displayCoinsScore.UR.y = 10;
	displayCoinsScore.LL.x = 1110;
	displayCoinsScore.LL.y = 40;
	displayCoinsScore.LR.x = 1210;
	displayCoinsScore.LR.y = 40;

	displayCoin.UL.x = 1230;
	displayCoin.UL.y = 10;
	displayCoin.UR.x = 1260;
	displayCoin.UR.y = 10;
	displayCoin.LL.x = 1230;
	displayCoin.LL.y = 40;
	displayCoin.LR.x = 1260;
	displayCoin.LR.y = 40;
	displayCoinAnimation = 0;
	displayCoinFrames = 0;
	
	

}

void Coins::Initialize3() {

	#pragma region CoinPos

	/*coins3[0].UL.x = 100;
	coins3[0].UL.y = 400;
	coins3[0].UR.x = 130;
	coins3[0].UR.y = 400;
	coins3[0].LL.x = 100;
	coins3[0].LL.y = 430;
	coins3[0].LR.x = 130;
	coins3[0].LR.y = 430;*/

	coins3[0].UL.x = 150;
	coins3[0].UL.y = 530;
	coins3[0].UR.x = 180;
	coins3[0].UR.y = 530;
	coins3[0].LL.x = 150;
	coins3[0].LL.y = 560;
	coins3[0].LR.x = 180;
	coins3[0].LR.y = 560;

	coins3[1].UL.x = 2470;
	coins3[1].UL.y = 400;
	coins3[1].UR.x = 2500;
	coins3[1].UR.y = 400;
	coins3[1].LL.x = 2470;
	coins3[1].LL.y = 430;
	coins3[1].LR.x = 2500;
	coins3[1].LR.y = 430;

	coins3[2].UL.x = 3850;
	coins3[2].UL.y = 370;
	coins3[2].UR.x = 3880;
	coins3[2].UR.y = 370;
	coins3[2].LL.x = 3850;
	coins3[2].LL.y = 400;
	coins3[2].LR.x = 3880;
	coins3[2].LR.y = 400;

#pragma endregion

	isScrollXBackward = false;
	isScrollXForward = false;

	scrollSpeed = {0, 0};
	coinHandle = Novice::LoadTexture("./Sprites/Coin.png");
	displayCoinsScoreHandle = Novice::LoadTexture("./Sprites/Score.png");
	coinSize = {30, 30};
	for (int i = 0; i < MAXCOINS; i++) {
		coinTaken3[i] = false;
		coinFrames[i] = 0;
		coinAnimation[i] = 0;
		displayCoinsAnimation3[i] = 0;
	}
	displayCoinsScore.UL.x = 1110;
	displayCoinsScore.UL.y = 10;
	displayCoinsScore.UR.x = 1210;
	displayCoinsScore.UR.y = 10;
	displayCoinsScore.LL.x = 1110;
	displayCoinsScore.LL.y = 40;
	displayCoinsScore.LR.x = 1210;
	displayCoinsScore.LR.y = 40;

	displayCoin.UL.x = 1230;
	displayCoin.UL.y = 10;
	displayCoin.UR.x = 1260;
	displayCoin.UR.y = 10;
	displayCoin.LL.x = 1230;
	displayCoin.LL.y = 40;
	displayCoin.LR.x = 1260;
	displayCoin.LR.y = 40;
	displayCoinAnimation = 0;
	displayCoinFrames = 0;
	
	

}

void Coins::ScrollCoins() {
	for (int i = 0; i < MAXCOINS; i++) {

		if (isScrollXForward) {

			coins[i].UL.x -= scrollSpeed.x;
			coins[i].UR.x -= scrollSpeed.x;
			coins[i].LL.x -= scrollSpeed.x;
			coins[i].LR.x -= scrollSpeed.x;
		}

		if (isScrollXBackward) {

			coins[i].UL.x += scrollSpeed.x;
			coins[i].UR.x += scrollSpeed.x;
			coins[i].LL.x += scrollSpeed.x;
			coins[i].LR.x += scrollSpeed.x;
		}
	}

}

void Coins::ScrollCoins2() {
	for (int i = 0; i < MAXCOINS; i++) {

		if (isScrollXForward) {

			coins2[i].UL.x -= scrollSpeed.x;
			coins2[i].UR.x -= scrollSpeed.x;
			coins2[i].LL.x -= scrollSpeed.x;
			coins2[i].LR.x -= scrollSpeed.x;
		}

		if (isScrollXBackward) {

			coins2[i].UL.x += scrollSpeed.x;
			coins2[i].UR.x += scrollSpeed.x;
			coins2[i].LL.x += scrollSpeed.x;
			coins2[i].LR.x += scrollSpeed.x;
		}
	}

}

void Coins::ScrollCoins3() {

	for (int i = 0; i < MAXCOINS; i++) {

		if (isScrollXForward) {

			coins3[i].UL.x -= scrollSpeed.x;
			coins3[i].UR.x -= scrollSpeed.x;
			coins3[i].LL.x -= scrollSpeed.x;
			coins3[i].LR.x -= scrollSpeed.x;
		}

		if (isScrollXBackward) {

			coins3[i].UL.x += scrollSpeed.x;
			coins3[i].UR.x += scrollSpeed.x;
			coins3[i].LL.x += scrollSpeed.x;
			coins3[i].LR.x += scrollSpeed.x;
		}
	}

}

void Coins::DisplayAnimation() {
	
	if (coinTaken[0] || coinTaken[1] || coinTaken[2]) {
		displayCoinsAnimation[0] = 1;
	}
	if (coinTaken[0] && coinTaken[1] || coinTaken[1] && coinTaken[2] ||
	    coinTaken[0] && coinTaken[2]) {
		displayCoinsAnimation[0] = 2;
	} 
	if (coinTaken[0] && coinTaken[1] && coinTaken[2]) {
		displayCoinsAnimation[0] = 3;
	}
	

}

void Coins::DisplayAnimation2() {

	if (coinTaken2[0] || coinTaken2[1] || coinTaken2[2]) {
		displayCoinsAnimation2[0] = 1;
	}
	if (coinTaken2[0] && coinTaken2[1] || coinTaken2[1] && coinTaken2[2] ||
	    coinTaken2[0] && coinTaken2[2]) {
		displayCoinsAnimation2[0] = 2;
	}
	if (coinTaken2[0] && coinTaken2[1] && coinTaken2[2]) {
		displayCoinsAnimation2[0] = 3;
	}

}

void Coins::DisplayAnimation3() {

	if (coinTaken3[0] || coinTaken3[1] || coinTaken3[2]) {
		displayCoinsAnimation3[0] = 1;
	}
	if (coinTaken3[0] && coinTaken3[1] || coinTaken3[1] && coinTaken3[2] ||
	    coinTaken3[0] && coinTaken3[2]) {
		displayCoinsAnimation3[0] = 2;
	}
	if (coinTaken3[0] && coinTaken3[1] && coinTaken3[2]) {
		displayCoinsAnimation3[0] = 3;
	}

}

void Coins::RotatingCoinAnimation() {

	for (int i = 0; i < MAXCOINS; i++) {
		if (!coinTaken[i]) {
			coinFrames[i]++;
		}
		if (coinFrames[i] >= 7) {
			coinAnimation[i]++;
			coinFrames[i] = 0;
		}
		if (coinAnimation[i] >= 6) {
			coinAnimation[i] = 0;
		}
	}
		displayCoinFrames++;
	
	if (displayCoinFrames>= 7) {
		displayCoinAnimation++;
		displayCoinFrames = 0;
	}
	if (displayCoinAnimation >= 6) {
		displayCoinAnimation  = 0;
	}
	for (int i = 0; i < 3; i++) {

		if (coinTaken[i]) {
			coins[i].UR.y += 7000;
			coins[i].UL.y += 7000;
			coins[i].LR.y += 7000;
			coins[i].LL.y += 7000;
		}
	}

}

void Coins::RotatingCoinAnimation2() {

	for (int i = 0; i < MAXCOINS; i++) {
		if (!coinTaken2[i]) {
			coinFrames[i]++;
		}
		if (coinFrames[i] >= 7) {
			coinAnimation[i]++;
			coinFrames[i] = 0;
		}
		if (coinAnimation[i] >= 6) {
			coinAnimation[i] = 0;
		}
	}
	displayCoinFrames++;

	if (displayCoinFrames >= 7) {
		displayCoinAnimation++;
		displayCoinFrames = 0;
	}
	if (displayCoinAnimation >= 6) {
		displayCoinAnimation = 0;
	}

	for (int i = 0; i < 3; i++) {

		if (coinTaken2[i]) {
			coins2[i].UR.y += 7000;
			coins2[i].UL.y += 7000;
			coins2[i].LR.y += 7000;
			coins2[i].LL.y += 7000;
		}
	}

}

void Coins::RotatingCoinAnimation3() {

		for (int i = 0; i < MAXCOINS; i++) {
		if (!coinTaken3[i]) {
			coinFrames[i]++;
		}
		if (coinFrames[i] >= 7) {
			coinAnimation[i]++;
			coinFrames[i] = 0;
		}
		if (coinAnimation[i] >= 6) {
			coinAnimation[i] = 0;
		}
	}
	displayCoinFrames++;

	if (displayCoinFrames >= 7) {
		displayCoinAnimation++;
		displayCoinFrames = 0;
	}
	if (displayCoinAnimation >= 6) {
		displayCoinAnimation = 0;
	}
}

void Coins::HowManyCoinsTaken() {

	if (displayCoinsAnimation[0] == 0) {
		howManyCoinsTaken = 0;
	}

	for (int i = 0; i < MAXCOINS; i++) {

		if (howManyCoinsTaken < displayCoinsAnimation[i]) {
			howManyCoinsTaken = displayCoinsAnimation[i];
		}
		if (playerFell) {
			displayCoinsAnimation[i] = 0;
			howManyCoinsTaken = 0;
			
			playerFell = false;
			
		}
	}
	
	 //Novice::ScreenPrintf(0, 0, "%d", howManyCoinsTaken);
}

void Coins::HowManyCoinsTaken2() {

		if (displayCoinsAnimation2[0] == 0) {
		howManyCoinsTaken2 = 0;
		}

		for (int i = 0; i < MAXCOINS; i++) {

			

		if (howManyCoinsTaken2 < displayCoinsAnimation2[i]) {
			howManyCoinsTaken2 = displayCoinsAnimation2[i];
		}
		if (playerFell) {
			displayCoinsAnimation2[i] = 0;
			howManyCoinsTaken2 = 0;
			playerFell = false;
		}
	}
	   

}

void Coins::HowManyCoinsTaken3() {

	if (displayCoinsAnimation3[0] == 0) {
		howManyCoinsTaken3 = 0;
	}

	for (int i = 0; i < MAXCOINS; i++) {

		if (howManyCoinsTaken3 < displayCoinsAnimation3[i]) {
			howManyCoinsTaken3 = displayCoinsAnimation3[i];
		}
		if (playerFell) {
			displayCoinsAnimation3[i] = 0;
			howManyCoinsTaken3 = 0;
			playerFell = false;
		}
	}
	for (int i = 0; i < MAXCOINS; i++) {

		if (coinTaken3[i]) {
			coins3[i].UR.y += 7000;
			coins3[i].UL.y += 7000;
			coins3[i].LR.y += 7000;
			coins3[i].LL.y += 7000;
		}
	}

}

void Coins::Update() {

	if (isScrollXForward || isScrollXBackward) {

		ScrollCoins();
	}
	DisplayAnimation();
	RotatingCoinAnimation();
	HowManyCoinsTaken();

}

void Coins::Update2() {
	if (isScrollXForward || isScrollXBackward) {

		ScrollCoins2();
	}
	DisplayAnimation2();
	HowManyCoinsTaken2();
	RotatingCoinAnimation2();

}

void Coins::Update3() {

	if (isScrollXForward || isScrollXBackward) {

		ScrollCoins3();
	}
	DisplayAnimation3();
	HowManyCoinsTaken3();
	


}

void Coins::Draw() {

	for (int i = 0; i < MAXCOINS; i++) {
		if (coins[i].UL.x >= -30 && coins[i].UL.x <= 1920 && !coinTaken[i]) {

			Novice::DrawQuad(
			    (int)coins[i].UL.x, (int)coins[i].UL.y, (int)coins[i].UR.x, (int)coins[i].UR.y,
			    (int)coins[i].LL.x, (int)coins[i].LL.y, (int)coins[i].LR.x, (int)coins[i].LR.y,
			    30 * coinAnimation[i],
			    0, 30, 30, coinHandle, WHITE);
		}
		
	}

	Novice::DrawQuad(
	    (int)displayCoinsScore.UL.x, (int)displayCoinsScore.UL.y, (int)displayCoinsScore.UR.x,
	    (int)displayCoinsScore.UR.y, (int)displayCoinsScore.LL.x, (int)displayCoinsScore.LL.y,
	    (int)displayCoinsScore.LR.x, (int)displayCoinsScore.LR.y, 100 * displayCoinsAnimation[0], 0,
	    100, 30,
	    displayCoinsScoreHandle, WHITE);

	Novice::DrawQuad(
	    (int)displayCoin.UL.x, (int)displayCoin.UL.y, (int)displayCoin.UR.x,
	    (int)displayCoin.UR.y, (int)displayCoin.LL.x, (int)displayCoin.LL.y,
	    (int)displayCoin.LR.x, (int)displayCoin.LR.y, 30 * displayCoinAnimation, 0,
	    30, 30, coinHandle, WHITE);

	
}

void Coins::Draw2() {

		for (int i = 0; i < MAXCOINS; i++) {
		if (coins2[i].UL.x >= -30 && coins2[i].UL.x <= 1920 && !coinTaken2[i]) {

			Novice::DrawQuad(
			    (int)coins2[i].UL.x, (int)coins2[i].UL.y, (int)coins2[i].UR.x, (int)coins2[i].UR.y,
			    (int)coins2[i].LL.x, (int)coins2[i].LL.y, (int)coins2[i].LR.x, (int)coins2[i].LR.y,
			    30 * coinAnimation[i], 0, 30, 30, coinHandle, WHITE);
		}
	}

	Novice::DrawQuad(
	    (int)displayCoinsScore.UL.x, (int)displayCoinsScore.UL.y, (int)displayCoinsScore.UR.x,
	    (int)displayCoinsScore.UR.y, (int)displayCoinsScore.LL.x, (int)displayCoinsScore.LL.y,
	    (int)displayCoinsScore.LR.x, (int)displayCoinsScore.LR.y, 100 * displayCoinsAnimation2[0], 0,
	    100, 30, displayCoinsScoreHandle, WHITE);

	Novice::DrawQuad(
	    (int)displayCoin.UL.x, (int)displayCoin.UL.y, (int)displayCoin.UR.x, (int)displayCoin.UR.y,
	    (int)displayCoin.LL.x, (int)displayCoin.LL.y, (int)displayCoin.LR.x, (int)displayCoin.LR.y,
	    30 * displayCoinAnimation, 0, 30, 30, coinHandle, WHITE);

	
}

void Coins::DrawScore() {

	Novice::DrawQuad(
	    (int)displayCoinsScore.UL.x, (int)displayCoinsScore.UL.y, (int)displayCoinsScore.UR.x,
	    (int)displayCoinsScore.UR.y, (int)displayCoinsScore.LL.x, (int)displayCoinsScore.LL.y,
	    (int)displayCoinsScore.LR.x, (int)displayCoinsScore.LR.y, 100 * displayCoinsAnimation3[0],
	    0, 100, 30, displayCoinsScoreHandle, WHITE);

	Novice::DrawQuad(
	    (int)displayCoin.UL.x, (int)displayCoin.UL.y, (int)displayCoin.UR.x, (int)displayCoin.UR.y,
	    (int)displayCoin.LL.x, (int)displayCoin.LL.y, (int)displayCoin.LR.x, (int)displayCoin.LR.y,
	    30 * displayCoinAnimation, 0, 30, 30, coinHandle, WHITE);

}

void Coins::Draw3() {

	for (int i = 0; i < MAXCOINS; i++) {
		if (coins3[i].UL.x >= -30 && coins3[i].UL.x <= 1920 && !coinTaken3[i]) {

			Novice::DrawQuad(
			    (int)coins3[i].UL.x, (int)coins3[i].UL.y, (int)coins3[i].UR.x, (int)coins3[i].UR.y,
			    (int)coins3[i].LL.x, (int)coins3[i].LL.y, (int)coins3[i].LR.x, (int)coins3[i].LR.y,
			    30 * coinAnimation[i], 0, 30, 30, coinHandle, WHITE);
		}
	}

	

	

}
