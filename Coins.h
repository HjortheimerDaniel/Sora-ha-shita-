#pragma once
#include "Struct.h"
#include "Novice.h"
#define MAXCOINS 3
class Coins {

	public:

	void InitializeCoinTaken();

	void InitializeCoinTaken2();

	void InitializeCoinTaken3();

	void Initialize();

	void Initialize2();

	void Initialize3();

	void ScrollCoins();

	void ScrollCoins2();

	void ScrollCoins3();

	void DisplayAnimation();

	void DisplayAnimation2();

	void DisplayAnimation3();

	void RotatingCoinAnimation();

	void RotatingCoinAnimation2();

	void RotatingCoinAnimation3();

	void SetScrollXForward(bool X) { isScrollXForward = X; }

	void SetScrollXBackward(bool X) { isScrollXBackward = X; }

	void SetScrollXSpeed(float X) { scrollSpeed.x = X; };

	void SetPlayerFell(bool x) { playerFell = x; };

	bool GetPlayerFell() { return playerFell; };

	Vector2 GetCoinSize() { return coinSize; };

	Quad* GetCoinPos() { return coins; };

	Quad* GetCoinPos2() { return coins2; };

	Quad* GetCoinPos3() { return coins3; };



	void SetCoinTaken(int index, bool taken) {
		
			coinTaken[index] = taken;
	}

	void SetCoinTaken2(int index, bool taken) { coinTaken2[index] = taken; }

	void SetCoinTaken3(int index, bool taken) { coinTaken3[index] = taken; }

	bool* GetCoinTaken() { return coinTaken; };

	bool* GetCoinTaken2() { return coinTaken2; };

	bool* GetCoinTaken3() { return coinTaken3; };

	int* GetDisplayCoinAnimation() { return displayCoinsAnimation; };

	int* GetDisplayCoinAnimation2() { return displayCoinsAnimation2; };

	int* GetDisplayCoinAnimation3() { return displayCoinsAnimation2; };

	void HowManyCoinsTaken();

	void HowManyCoinsTaken2();

	void HowManyCoinsTaken3();

	int GetHowManyCoinsTaken() { return howManyCoinsTaken; };

	int GetHowManyCoinsTaken2() { return howManyCoinsTaken2; };

	int GetHowManyCoinsTaken3() { return howManyCoinsTaken3; };

	void SetHowManyCoinsTaken2(int taken) {
		
			howManyCoinsTaken2 = taken;
	}

	void SetHowManyCoinsTaken3(int taken) { howManyCoinsTaken3 = taken; }

	void Update();

	void Update2();

	void Update3();

	void Draw();

	void Draw2();

	void DrawScore();

	void Draw3();


	private:

		Quad coins[MAXCOINS], coins2[MAXCOINS], coins3[MAXCOINS];
	    Quad displayCoin;
	    int coinHandle;
	    bool coinTaken[MAXCOINS], coinTaken2[MAXCOINS], coinTaken3[MAXCOINS];
	    bool isScrollXForward, isScrollXBackward, playerFell;
	    Vector2 scrollSpeed;
	    Vector2 coinSize;
	    int displayCoinsScoreHandle;
	    Quad displayCoinsScore;
	    int displayCoinsAnimation[MAXCOINS], displayCoinsAnimation2[MAXCOINS], displayCoinsAnimation3[MAXCOINS],
	        coinAnimation[MAXCOINS], coinFrames[MAXCOINS],
	        displayCoinAnimation, displayCoinFrames, howManyCoinsTaken, howManyCoinsTaken2, howManyCoinsTaken3;


};
