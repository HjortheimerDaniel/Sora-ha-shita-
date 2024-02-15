#pragma once
#include "Struct.h"
#include "Novice.h"
class Background {

	public:

		void BackgroundInitialize();

		void BackgroundInitialize2();

		void BackgroundInitialize3();

		void BackgroundSetScrollXSpeed(float speed) { scrollSpeed.x = speed; };

	    void BackgroundSetScrollXForward(bool X) { BackgroundisScrollXForward = X; }

	    void BackgroundSetScrollXBackward(bool X) { BackgroundisScrollXBackward = X; }

		void BackgroundSetReversed1(float reverse) { reverseSize = reverse; };

		void BackgroundSetReversed2(int reverse) { reversed[0] = reverse; };

		void BackgroundSetReversed3(int reverse) { reversed[1] = reverse; };

		void Reverse();

	    void SetColor(int X) { Backgroundcolor = X; };

		void BackgroundScroll();

		void BackgroundScroll2();

		void BackgroundScroll3();

		void BackgroundUpdate();

		void BackgroundUpdate2();

		void BackgroundUpdate3();

		void BackgroundDraw();

		void BackgroundDraw2();

		void BackgroundDraw3();


	private:

		#pragma region Stage1

		Vector2 backgroundPos[MAXBACKGROUNDS];
	    int handle[MAXBACKGROUNDS];
	    bool BackgroundisScrollXForward, BackgroundisScrollXBackward;
	    Vector2 scrollSpeed;
	    int Backgroundcolor;
	    int reversed[2];
	    float reverseSize;
		
		#pragma endregion

		#pragma region Stage2

	    Vector2 backgroundPos2[MAXBACKGROUNDS2];
	    int handle2[MAXBACKGROUNDS2];

		#pragma endregion

		#pragma region Stage2

	    Vector2 backgroundPos3[MAXBACKGROUNDS2];
	    int handle3[MAXBACKGROUNDS2];

	#pragma endregion


};
