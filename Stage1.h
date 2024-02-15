#pragma once
#include "Player.h"
#include "Functions.h"
#include "XScroll.h"
#include "Novice.h"
#include "ClearDoor.h"
#include "Coins.h"
#include "Wind.h"
#include "Background.h"
#define MAXLINES 12

class Stage1: public Wind, public Background {

	public:

		void InitializeOnce();

		void Initialize();

		bool GetStageComplete() { return stageComplete; };

		Coins* GetCoins() { return coins; };

		Player* GetPlayer() { return player; };
		void Reset(char* keys);

		void ScrollStage(char* keys, char* preKeys);

		void ScrollXSpeed();

		void CollisionPlayerEnd();

		void CollisionPlayerCoin();

		void BlackenScreen();

		void Gravity();

		void Music();

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
	   // Background* background = new Background();
	    Coins* coins = new Coins();
	    Vector2 distanceFP;
	    Vector2 normalize;
	    Vector2 fixDist;
	    float scrollX;
	    bool stageComplete;
	    Vector2 blackScreen;
	    int seeThrough, restartTimer;
	    bool stage1Coins[3];
	    int coinAudio;
	    int voiceHandle;
	    int voiceHandle1;
	    int voiceHandle2;
	    int BGM;
	    int BGM2;
	    float volume[2];
		

	    //Vector2 lineStart[MAXLINES];
	    //Vector2 lineEnd[MAXLINES];


};
