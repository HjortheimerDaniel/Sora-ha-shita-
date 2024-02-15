#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Struct.h"
#include "Novice.h"
#include "XScroll.h"

#define MAXLines 12
#define MAXMovingLines 3

class Floor {

public:
	void Initialize();

	void Initialize2();

	void Initialize3();

	Vector2* GetLineStart() { return lineStart; };

	Vector2* GetLineSize() { return lineSize; };

	Vector2* GetLineEnd() { return lineEnd; };

	float GetTheta() { return theta; };

	void SetScrollXForward(bool X) { isScrollXForward = X; }

	void SetScrollXBackward(bool X) { isScrollXBackward = X; }

	void SetLineStart(Vector2 start[]) {
		for (int i = 0; i < MAXLines; i++) {
			lineStart[i] = start[i];
		}
	}

	void SetLineEnd(Vector2 end[]) {
		for (int i = 0; i < MAXLines; i++) {
			lineStart[i] = end[i];
		}
	}

	void ScrollFloor();

	void MovingPlatforms();

	void Sprites();

	void Update();

	void Update2();

	void Update3();

	void Draw();

	void Draw2();

	void Draw3();

private:
	XScroll* xScroll = new XScroll();
	Vector2 lineStart[MAXLines];
	Vector2 lineEnd[MAXLines];
	Vector2 lineSize[MAXLines], movingPlatformStart[MAXMovingLines],movingPlatformEnd[MAXMovingLines];
	bool isScrollXForward;
	bool isScrollXBackward, goLeft[MAXMovingLines], goRight[MAXMovingLines];
	int scrollSpeed, movingPlatformSize, startPoint[MAXMovingLines], platformSpeed, directionTimer, sizeHandle[3], handle;
	int sizeHandleStage1[4], sizeHandleStage2[4];
	float lineMovement, amplitude, amplitude2, theta;
	

};
