#pragma once
#include "Struct.h"
#include "Novice.h"
#include <time.h> 
#define MAXNUMBER 30

class GameClear {

	public:

		void Initialize();

		void CoinAnimation();

		void FallingCoins();

		void Update();

		void DrawCoins();

		void Draw();

		private:

			ClearStruct clear;
	        Vector2 coins[MAXNUMBER];
	        int coinHandle;
	        int coinSize;
	        bool isFalling[MAXNUMBER];
	        int speed[MAXNUMBER];
	        unsigned int seed;
	        int delay;
};
