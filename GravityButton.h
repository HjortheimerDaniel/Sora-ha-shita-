#pragma once
#include "Struct.h"
#include "Novice.h"
#define MAXBLOCKS 6


class GravityButton {

public:
	void Initialize();

	void Initialize2();

	void Initialize3();

	// ADD BLOCK POSITION AND COLLISION IN PLAYER.CPP

	Quad* GetBlockUpPos() { return gravityUpwardsBlock; };

	Quad* GetBlockDownPos() { return gravityDownwardsBlock; };

	Vector2 GetBlockUpSize() { return upSize; };

	void SetScrollXForward(bool X) { isScrollXForward = X; }

	void SetScrollXBackward(bool X) { isScrollXBackward = X; }

	void SetScrollXSpeed(float X) { scrollSpeed.x = X; };

	void ScrollButton();

	void Update();

	void Draw();

private:
	    Quad gravityUpwardsBlock[MAXBLOCKS];
	    Quad gravityDownwardsBlock[MAXBLOCKS];
	    int blockHandle;
	    Vector2 upSize;
	    bool isScrollXForward, isScrollXBackward;
	    Vector2 scrollSpeed;


};
