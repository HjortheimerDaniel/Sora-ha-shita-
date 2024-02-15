#pragma once
#include "Struct.h"
#define USE_MATH_DEFINES_
#include <math.h>
#include <time.h>
#include<cstdlib>
#include "Novice.h"

#define MAXPARTICLES 60

class Wind {

	public:

	void InitializeWind();

	void BlowWind();

	void GravityReversed();

	void ScrollWind();

	void UpdateWind();

	void DrawWind();

	void Draw();


	protected:

		Vector2 windParticles[MAXPARTICLES];
	    int radius[MAXPARTICLES];
	    int speedY[MAXPARTICLES];
	    int speedX[MAXPARTICLES];
	    bool isBlowing[MAXPARTICLES];
	    Vector2 emitterSize;
	    Vector2 emitter;
	    unsigned int seed;
	    int windColor;
	    float windMiddle;
	    bool startBlowing;
	    int windTimer, scrollSpeed;
	    int gravityReverse;
	    bool isGravityReversed;
	    bool isScrollXForwardWind, isScrollXBackwardWind;



};
