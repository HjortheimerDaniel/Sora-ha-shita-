#pragma once
#include "ClearDoor.h"
#include "Coins.h"
#include "Functions.h"
#include "Novice.h"
#include "Player.h"
#include "XScroll.h"
#include "Spikes.h"
#include "Wind.h"
#include "Background.h"
#define MAXLINES 12
#define MAXSPIKES 8

class Stage2: public Wind, public Background {

public:

	void Initialize(Coins* coinss);

	bool GetStageComplete() { return stageComplete; };

	Coins* GetCoins() { return coins; };

	Player* GetPlayer() { return player; };

	void Music();

	void Reset(char* keys);

	void ScrollStage(char* keys, char* preKeys);

	void ScrollXSpeed();

	void CollisionPlayerEnd();

	void CollisionPlayerCoin();

	void CollisionPlayerSpikes();

	void BlackenScreen();

	void Gravity();

	void Update(char* keys, char* preKeys);

	void DrawBlackScreen();

	void Draw();

	void Debug(char* keys, char* preKeys);

private:

	Player* player = new Player();
	Floor* floor = new Floor();
	GravityButton* gravity = new GravityButton();
	XScroll* xScroll = new XScroll();
	StageClear* stageClear = new StageClear();
	Coins* coins;
	Spikes* spikes = new Spikes();
	Vector2 distanceFP;
	Vector2 normalize;
	Vector2 fixDist;
	float scrollX;
	bool stageComplete;
	Vector2 blackScreen;
	int seeThrough, restartTimer;
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
