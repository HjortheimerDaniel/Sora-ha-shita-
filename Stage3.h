#pragma once
#include "ClearDoor.h"
#include "Coins.h"
#include "Functions.h"
#include "Novice.h"
#include "Player.h"
#include "Spikes.h"
#include "XScroll.h"
#include "TimeAccessory.h"
#include "Wind.h"
#include "Background.h"
#define MAXLINES  12
#define MAXSPIKES 8
#define MAXSPIKESLONG 10
#define MAXSQUARES    4

class Stage3 : public Wind, public Background
{

	public:

		void Initialize(Coins* coinss);

		void InitializeOnce();

		bool GetStageComplete() { return stageComplete; };

		Coins* GetCoins() { return coins; };

		Player* GetPlayer() { return player; };

		void Reset(char* keys);

		void Music();

		void ScrollStage(char* keys, char* preKeys);

		void ScrollXSpeed();

		void CollisionPlayerEnd();

		void CollisionPlayerCoin();

		void CollisionPlayerSpikes();

		void CollisionPlayerDeathCube();

		void BlackenScreen();

		void Cutscene(char* keys, char* preKeys);

		void Gravity();

		void Update(char* keys, char* preKeys);

		void DrawBlackScreen();

		void DrawStopTime();

		void DrawCutscene();

		void Draw();

		void Debug(char* keys, char* preKeys);

	private:
		Player* player = new Player();
		Floor* floor = new Floor();
		GravityButton* gravity = new GravityButton();
		XScroll* xScroll = new XScroll();
		StageClear* stageClear = new StageClear();
		Coins* coins = new Coins();
		Spikes* spikes = new Spikes();
	    TimeAccessory* timeAccessory = new TimeAccessory();
	   // Wind* wind = new Wind();
		Vector2 distanceFP;
		Vector2 normalize;
		Vector2 fixDist;
		float scrollX;
		bool stageComplete, cutsceneEnd;
		Vector2 blackScreen;
		int seeThrough, restartTimer, stopTimeHandle;
	    int cutsceneHandle, cutsceneEndTimer;
	    Text text;
	    int coinAudio;
	    int voiceHandle;
	    int voiceHandle1;
	    int voiceHandle2;
	    int BGM;
	    int BGM2;
	    float volume[2];

		// Vector2 lineStart[MAXLINES];
		// Vector2 lineEnd[MAXLINES];
	};



