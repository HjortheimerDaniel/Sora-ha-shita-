#pragma once
#include "Struct.h"
#include "Novice.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define MAXSPIKES 8
#define MAXSPIKESLONG 10
#define MAXMOVINGSPIKES 2
#define MAXSQUARES 4
class Spikes {

	public:

		void Initialize();

		void Initialize2();

		void SetScrollXForward(bool X) { isScrollXForward = X; };

	    void SetScrollXBackward(bool X) { isScrollXBackward = X; };

		Vector2* GetSpikePos() { return spikeCollision; };

		Vector2* GetSpikePosLong() { return spikeCollisionLong; };

		Vector2* GetSpikeSize() { return collisionSize; };

		Vector2* GetSpikeSizeLong() { return collisionSizeLong; };

		Vector2* GetSpikeBasePos() { return spikeBasePos; };

		Vector2 GetSpikeBaseSize() { return spikeBaseSize; };

		void SpikeCollision();

		void SpikeCollisionLong();

		void SpriteHandle();

		void SpriteHandle2();

		void ScrollSpikes();

		void ScrollSpikes2();

		void ScrollSpikesLong();

		void MovingSpikes();

		void MovingSpikesLong();

		void Update();

		void Update2();

		void Draw();

		void Draw2();

	private:

		Vector2 spikePos[MAXSPIKES], spikePosLong[MAXSPIKESLONG], spikeSize[MAXSPIKES],
	        spikeSizeLong[MAXSPIKESLONG], movingSpikePos[MAXMOVINGSPIKES],
	        movingSpikePosLong[MAXSPIKESLONG], spikeCollision[MAXSPIKES],
	        spikeCollisionLong[MAXSPIKESLONG], collisionSize[MAXSPIKES], collisionSizeLong[MAXSPIKESLONG],
	        spikeBasePos[MAXSQUARES], originalSpikeBasePos[MAXSQUARES], spikeBaseSize;
	    int spikeHandle[MAXSPIKES], spikeHandleLong[MAXSPIKESLONG],
	        scrollSpeed, spikeOriginal,
	        spikeUpsideDown, spikePointLeft, spikePointRight, spikeBaseHandle;
	    bool isScrollXForward, isScrollXBackward;
	    float theta, amplitude, amplitude2;



};
