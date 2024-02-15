#pragma once
#include "Struct.h"
#include "Jump.h"
#include "Novice.h"
#include "Floor.h"
#include "Functions.h"
#include "GravityButton.h"
#include "XScroll.h"
#include <time.h>
#define MAXLines 12
#define MAXBLOCKS 6
#define MAXAFTERIMAGES 60

class Player {

	public:

		void Initialize();

		void Initialize2();

		void Initialize3();

		#pragma region GET

		Quad GetPlayerPos() { return player.pos; };

		Quad GetPlayerHitBoxPos() { return player.hitbox; };

		Vector2 GetPlayerSpeed() { return player.speed; };

		Vector2 GetPlayerSize() { return player.size; };

		Vector2 GetPlayerHitBoxSize() { return player.hitboxSize; };

		int GetDeathTimer() { return shakeTimer; };

		int GetRandX() { return randX; };

		int GetRandY() { return randY; };

		bool GetPlayerSpiked() { return playerSpiked; };

		bool GetPlayerDead() { return playerDead; };

		bool GetGravityReverse() { return gravityReverse; };

		bool GetIsTimeStopped() { return isTimeStopped; };

		#pragma endregion

		#pragma region SET

		void SetAccY(float Y) { player.acceleration.y = Y; };

		void SetVelY(float Y) { player.velocity.y = Y; };

		void SetPlayerSpiked(bool x) { playerSpiked = x; };

		void SetIsTimeStopped(bool x) { isTimeStopped = x; };

		void SetEndOfScreen(int x) { endOfScreen = x; };

		void SetRandX(int x) { randX = x; };

		void SetRandY(int x) { randY = x; };

		#pragma endregion

		void Scroll();

		void Tunneling();

		void DeathAnimation();

		void PlayerDead();

		void PlayerShake();

		void AfterImages();

		void HitBox();

		void Audio(char* keys, char* preKeys);

		void Jump(char* keys, char* preKeys);

		void Walk(char* keys, char* preKeys);
		
		void Gravity(char* keys, char* preKeys);

		void Animation(char* keys, char* preKeys);

		void Movement(char* keys, char* preKeys);

		void Update(char* keys, char* preKeys);

		void Update2(char* keys, char* preKeys);

		void Update3(char* keys, char* preKeys);

		void UpdatePlayerDead();

		void DrawAfterImages();

		void DrawDeathAnimation();

		void Draw();


	private:

		PlayerStruct player;
	    Floor* floor = new Floor();
	    GravityButton* gravityButton = new GravityButton();
	    XScroll* xScroll = new XScroll();
	    bool gravityReverse;
	    float gravity;
	    bool isGravityChanged, dontShake, hitHead, shake, playerSpiked, playerDead,isTimeStopped;
	    int gravityTimer, hitHeadTimer, randStart, randEnd, shakeTimer, amplitude;
	    unsigned int randX, randY, seed;
	    Vector2 testVel;
	    Vector2 newLineStart[MAXLines];
	    Vector2 newLineEnd[MAXLines];
	    Vector2 newGravityUpButton[MAXBLOCKS];
	    Vector2 newGravityDownButton[MAXBLOCKS];
	    Vector2 newMovingLines[MAXMovingLines];
	    float theta;
	    int R, G, B, A[MAXAFTERIMAGES];
	    int seeThroughAfterImage[MAXAFTERIMAGES];
	    int isDraw[MAXAFTERIMAGES] = {};
	    int afterImageColor[MAXAFTERIMAGES]{};
	    Vector2 afterImagePos[MAXAFTERIMAGES];
	    bool invisible[MAXAFTERIMAGES];
	    int timer;
	    int endOfScreen;
	    bool playerDeadAnimation;
	    int jumpAudio;
	    int offScreenAudio;
	    int voiceHandle;
		
		
		
	   


};
