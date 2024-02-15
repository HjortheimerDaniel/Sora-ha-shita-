#include "Spikes.h"

void Spikes::Initialize() {

	#pragma region Pos

	#pragma region Original

	spikePos[0].x = 400;
	spikePos[0].y = 479;
	spikeSize[0].x = 300;
	spikeSize[0].y = 20;

	spikePos[2].x = 840;
	spikePos[2].y = 479;
	spikeSize[2].x = 300;
	spikeSize[2].y = 20;

	spikePos[4].x = 1400;
	spikePos[4].y = 79;
	spikeSize[4].x = 300;
	spikeSize[4].y = 20;

	spikePos[6].x = 1700;
	spikePos[6].y = 579;
	spikeSize[6].x = 300;
	spikeSize[6].y = 20;

	spikePos[7].x = 3850;
	spikePos[7].y = 510;
	spikeSize[7].x = 300;
	spikeSize[7].y = 20;

	#pragma endregion

	#pragma region Reverse

	spikePos[1].x = 300;
	spikePos[1].y = 30;
	spikeSize[1].x = 300;
	spikeSize[1].y = 20;

	spikePos[3].x = 700;
	spikePos[3].y = 30;
	spikeSize[3].x = 300;
	spikeSize[3].y = 20;

	spikePos[5].x = 3200;
	spikePos[5].y = 233;
	spikeSize[5].x = 300;
	spikeSize[5].y = 20;

	movingSpikePos[0].x = 3200;
	movingSpikePos[0].y = 327;
	movingSpikePos[1].x = 3850;
	movingSpikePos[1].y = 527;

	#pragma endregion

	#pragma endregion

	spikeOriginal = Novice::LoadTexture("./Sprites/Spikes.png");
	spikeUpsideDown = Novice::LoadTexture("./Sprites/SpikesSakasama.png");
	for (int i = 0; i < MAXSPIKES; i++) {

		spikeHandle[i] = Novice::LoadTexture("./Sprites/Spikes.png");
	}
	isScrollXBackward = false;
	isScrollXForward = false;
	scrollSpeed = 5;
	theta = 0.0f;
	amplitude = 150.0f;
	amplitude2 = -150.0f;
	for (int i = 0; i < MAXSPIKES; i++) {
		collisionSize[i].x = spikeSize[i].x;
		collisionSize[i].y = 5;
	}

}

void Spikes::Initialize2() {

	
	#pragma region Pos

#pragma region Original

	spikePosLong[0].x = 2350;
	spikePosLong[0].y = -129;
	spikeSizeLong[0].x = 20;
	spikeSizeLong[0].y = 500;

	spikePosLong[1].x = 2350;
	spikePosLong[1].y = 629;
	spikeSizeLong[1].x = 20;
	spikeSizeLong[1].y = 500;

	spikePosLong[2].x = 2571;
	spikePosLong[2].y = -129;
	spikeSizeLong[2].x = 20;
	spikeSizeLong[2].y = 500;

	spikePosLong[3].x = 2571;
	spikePosLong[3].y = 629;
	spikeSizeLong[3].x = 20;
	spikeSizeLong[3].y = 500;

	spikePosLong[4].x = 2950;
	spikePosLong[4].y = -129;
	spikeSizeLong[4].x = 20;
	spikeSizeLong[4].y = 500;

	spikePosLong[5].x = 2950;
	spikePosLong[5].y = 629;
	spikeSizeLong[5].x = 20;
	spikeSizeLong[5].y = 500;

	spikePosLong[6].x = 3171;
	spikePosLong[6].y = -129;
	spikeSizeLong[6].x = 20;
	spikeSizeLong[6].y = 500;

	spikePosLong[7].x = 3171;
	spikePosLong[7].y = 629;
	spikeSizeLong[7].x = 20;
	spikeSizeLong[7].y = 500;

	//spikePosLong[8].x = 3700;
	//spikePosLong[8].y = 459;
	//spikeSizeLong[8].x = 500;
	//spikeSizeLong[8].y = 20;

	spikePosLong[8].x = 3700;
	spikePosLong[8].y = 459;
	spikeSizeLong[8].x = 300;
	spikeSizeLong[8].y = 20;

	spikePosLong[9].x = 3700;
	spikePosLong[9].y = 303;
	spikeSizeLong[9].x = 300;
	spikeSizeLong[9].y = 20;

	spikeBasePos[0].x = 2370;
	spikeBasePos[0].y = -129;

	spikeBasePos[1].x = 2370;
	spikeBasePos[1].y = 629;

	spikeBasePos[2].x = 2970;
	spikeBasePos[2].y = -129;

	spikeBasePos[3].x = 2970;
	spikeBasePos[3].y = 629;

	//spikePos[2].x = 840;
	//spikePos[2].y = 479;
	//spikeSize[2].x = 300;
	//spikeSize[2].y = 20;

	//spikePos[4].x = 1400;
	//spikePos[4].y = 79;
	//spikeSize[4].x = 300;
	//spikeSize[4].y = 20;

	//spikePos[6].x = 1700;
	//spikePos[6].y = 579;
	//spikeSize[6].x = 300;
	//spikeSize[6].y = 20;

	//spikePos[7].x = 3850;
	//spikePos[7].y = 505;
	//spikeSize[7].x = 300;
	//spikeSize[7].y = 20;

#pragma endregion

#pragma region Reverse
	
	//spikePos[3].x = 700;
	//spikePos[3].y = 30;
	//spikeSize[3].x = 300;
	//spikeSize[3].y = 20;
	//
	//spikePos[5].x = 3200;
	//spikePos[5].y = 233;
	//spikeSize[5].x = 300;
	//spikeSize[5].y = 20;

	movingSpikePosLong[0].x = 2350;
	movingSpikePosLong[0].y = -129;
	movingSpikePosLong[1].x = 3850;
	movingSpikePosLong[1].y = 629;
	movingSpikePosLong[2].y = -129;
	movingSpikePosLong[3].y = 629;
	movingSpikePosLong[4].y = -129;
	movingSpikePosLong[5].y = 629;
	movingSpikePosLong[6].y = -129;
	movingSpikePosLong[7].y = 629;

	originalSpikeBasePos[0].x = 2370;
	originalSpikeBasePos[0].y = -129;
	originalSpikeBasePos[1].x = 2370;
	originalSpikeBasePos[1].y = 629;
	originalSpikeBasePos[2].x = 2970;
	originalSpikeBasePos[2].y = -129;
	originalSpikeBasePos[3].x = 2970;
	originalSpikeBasePos[3].y = 629;

	spikeBaseSize = {200, 500};

#pragma endregion

#pragma endregion

	spikeOriginal = Novice::LoadTexture("./Sprites/Spikes.png");
	spikeUpsideDown = Novice::LoadTexture("./Sprites/SpikesSakasama.png");
	spikePointLeft = Novice::LoadTexture("./Sprites/SpikesPointLeftLong.png");
	spikePointRight = Novice::LoadTexture("./Sprites/SpikesPointRightLong.png");
	spikeBaseHandle = Novice::LoadTexture("./Sprites/SpikeBody.png");

	for (int i = 0; i < MAXSPIKESLONG; i++) {
		spikeHandleLong[i] = Novice::LoadTexture("./Sprites/Spikes.png");
	}


	isScrollXBackward = false;
	isScrollXForward = false;
	scrollSpeed = 5;
	theta = 0.0f;
	amplitude = 150.0f;
	amplitude2 = -300.0f;
	for (int i = 0; i < MAXSPIKESLONG; i++) {
		collisionSizeLong[i].x = spikeSizeLong[i].x;
		collisionSizeLong[i].y = spikeSizeLong[i].y -7;

	}
}


void Spikes::SpikeCollision() {

	for (int i = 0; i < MAXSPIKES; i++) {
		spikeCollision[i].x = spikePos[i].x;

		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7) {
			spikeCollision[i].y = spikePos[i].y;
		} else {
			spikeCollision[i].y = spikePos[i].y +  15;
		}
	}
}

void Spikes::SpikeCollisionLong() {

		for (int i = 0; i < MAXSPIKESLONG; i++) {
		spikeCollisionLong[i].x = spikePosLong[i].x;

		if (i == 0 || i == 1 || i == 4 || i == 6 || i == 7 || i == 8) {
			spikeCollisionLong[i].y = spikePosLong[i].y;
		} else {
			spikeCollisionLong[i].y = spikePosLong[i].y + 10;
		}
	}

}

void Spikes::SpriteHandle() {

	for (int i = 0; i < MAXSPIKES; i++) {
		if (i % 2 == 0 || i == 7) {
			spikeHandle[i] = spikeOriginal;
		} else{
			spikeHandle[i] = spikeUpsideDown;
		}
	}

}

void Spikes::SpriteHandle2() {
	
	for (int i = 0; i < MAXSPIKESLONG; i++) {
		if (i == 0 || i == 1 || i == 4 || i == 5) {
			spikeHandleLong[i] = spikePointLeft;
		} else {
			spikeHandleLong[i] = spikePointRight;
		}
	}
	spikeHandleLong[8] = spikeOriginal;
	spikeHandleLong[9] = spikeUpsideDown;



	/*for (int i = 0; i < 2; i++) {
			spikeHandle[i] = spikePointLeft;
		} 
	for (int i = 2; i < 4; i++) {
		    spikeHandle[i] = spikePointRight;
	    }*/
	

}

void Spikes::ScrollSpikes() {

		if (isScrollXForward) {
		for (int i = 0; i < MAXSPIKES; i++) {
			spikePos[i].x -= scrollSpeed;
			//lineStart[i].x -= scrollSpeed;
		}
		for (int i = 0; i < MAXMOVINGSPIKES; i++) {
			movingSpikePos[i].x -= scrollSpeed;
		}
	}

		if (isScrollXBackward) {
		for (int i = 0; i < MAXSPIKES; i++) {
			spikePos[i].x += scrollSpeed;
			//lineStart[i].x += scrollSpeed;
		}
		for (int i = 0; i < MAXMOVINGSPIKES; i++) {
			movingSpikePos[i].x += scrollSpeed;
		}

	}

}

void Spikes::ScrollSpikes2() {

	if (isScrollXForward) {
		for (int i = 0; i < MAXSPIKESLONG; i++) {
			movingSpikePosLong[i].x -= scrollSpeed;
		}
	}
	if (isScrollXBackward) {

		for (int i = 0; i < MAXSPIKESLONG; i++) {
			movingSpikePosLong[i].x += scrollSpeed;
		}
	}

}

void Spikes::ScrollSpikesLong() {

	if (isScrollXForward) {
		for (int i = 0; i < MAXSPIKESLONG; i++) {
			spikePosLong[i].x -= scrollSpeed;
			
			// lineStart[i].x -= scrollSpeed;
		}
		for (int i = 0; i < MAXSQUARES; i++) {
			spikeBasePos[i].x -= scrollSpeed;
		}
		
	}
	if (isScrollXBackward) {
		for (int i = 0; i < MAXSPIKESLONG; i++) {
			spikePosLong[i].x += scrollSpeed;
			
			// lineStart[i].x += scrollSpeed;
		}
		for (int i = 0; i < MAXSQUARES; i++) {
			spikeBasePos[i].x += scrollSpeed;
		}
	}

}

void Spikes::MovingSpikes() {

	theta += float(M_PI) / 250.0f;

	spikePos[5].x = cosf(theta) * amplitude2 + movingSpikePos[0].x;
	spikePos[7].x = cosf(theta) * amplitude + movingSpikePos[1].x;
	
}

void Spikes::MovingSpikesLong() {

	theta += float(M_PI) / 100.0f;
	for (int i = 0; i < 8; i++) {

		spikePosLong[i].y = sinf(theta) * amplitude2 + movingSpikePosLong[i].y;
		
	}
	for (int i = 0; i < MAXSQUARES; i++) {
		spikeBasePos[i].y = sinf(theta) * amplitude2 + originalSpikeBasePos[i].y;
	}


	//spikePos[7].x = sin(theta) * amplitude + movingSpikePos[1].x;

}

void Spikes::Update() {

	ScrollSpikes();
	SpriteHandle();
	MovingSpikes();
	SpikeCollision();
}

void Spikes::Update2() { 
	SpikeCollision();
	SpikeCollisionLong();
	ScrollSpikes2();
	ScrollSpikesLong();
	SpriteHandle2();

}

void Spikes::Draw() {

	for (int i = 0; i < MAXSPIKES; i++) {
		Novice::DrawSprite(
		    (int)spikePos[i].x, (int)spikePos[i].y, spikeHandle[i], 1, 1, 0.0f, WHITE);

		/*Novice::DrawBox(
		    (int)spikeCollision[i].x, (int)spikeCollision[i].y, (int)collisionSize[i].x,
		    (int)collisionSize[i].y, 0.0f, WHITE, kFillModeWireFrame);*/

		/*if (i % 2 == 0) {

			Novice::DrawSprite(
			    (int)spikePos[i].x, (int)spikePos[i].y, spikeOriginal, 1, 1, 0.0f, WHITE);
		} else {
			Novice::DrawSprite(
			    (int)spikePos[i].x, (int)spikePos[i].y, spikeUpsideDown, 1, 1, 0.0f, WHITE);
		}*/
	}

}



void Spikes::Draw2() {

	
	for (int i = 0; i < MAXSPIKESLONG; i++) {
		Novice::DrawSprite(
		    (int)spikePosLong[i].x, (int)spikePosLong[i].y, spikeHandleLong[i], 1, 1, 0.0f, WHITE);

		/*Novice::DrawBox(
		    (int)spikeCollisionLong[i].x, (int)spikeCollisionLong[i].y, (int)collisionSizeLong[i].x,
		    (int)collisionSizeLong[i].y, 0.0f, WHITE, kFillModeWireFrame);*/

		/*Novice::DrawBox(
		    (int)spikeCollisionLong[i].x, (int)spikeCollisionLong[i].y, (int)collisionSizeLong[i].x,
		    (int)collisionSizeLong[i].y, 0.0f, WHITE, kFillModeWireFrame);*/
		
	}
	for (int i = 0;  i < MAXSQUARES;  i++) {
		Novice::DrawSprite((int)spikeBasePos[i].x, (int)spikeBasePos[i].y, spikeBaseHandle, 1, 1, 0.0f, WHITE);

	}

	//Novice::ScreenPrintf(0, 20, "%f", spikeCollision[7].x);

}


