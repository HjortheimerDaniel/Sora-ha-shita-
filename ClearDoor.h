#pragma once
#include "Struct.h"
#include "Novice.h"

class StageClear {

	public:

		void Initialize();

		void Initialize2();

		void Initialize3();

		void Scroll();

		void SetScrollXSpeed(float speed) { scrollSpeed.x = speed; };

		void SetScrollXForward(bool X) { isScrollXForward = X; }

	    void SetScrollXBackward(bool X) { isScrollXBackward = X; }

		void SetStageOnScreen(bool X) { stageOnScreen = X; };

		Quad GetFinishPos() { return finishPos; };

		Vector2 GetFinishSize() { return finishSize; };

		void Update();

		void Draw();


	private:

		int clearHandle;
	    Quad finishPos;
	    Vector2 finishSize;
	    Vector2 scrollSpeed;
	    bool isScrollXForward, isScrollXBackward, stageOnScreen;
	    bool isReversed;



};
