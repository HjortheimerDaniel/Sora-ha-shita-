#pragma once
#include "Struct.h"
#include "Novice.h"
#include "Coins.h"
#include "Player.h"
#define MAXSTAGES 3

class StageSelect {

	public:

		void Initialize(Coins* coinss, Player* playerr);

		void StageAnimation(char* keys, char* preKeys);

		void ControlsMenu(char* keys, char* preKeys);

		void Music();

		void Update(char* keys, char* preKeys);

		void Update2();

		void Update3();

		int* GetStageAnimation() { return stageAnimation; };

		void SetStageFinished(bool x) { stageFinished[0] = x; };

		void SetStageFinished2(bool x) { stageFinished[1] = x; };

		void SetStageFinished3(bool x) { stageFinished[2] = x; };

		void SetIsStage3Reached(bool x) { isStage3Reached = x; };

		bool GetIsPauseMenu() { return isPauseMenu; };

		int GetStagesClear() { return stagesClear; };

		void CoinsTaken();

		void CoinsTaken2();

		void CoinsTaken3();

		void DrawCoins();

		void StagesCleared();

		void StagesCleared2();

		void StagesCleared3();

		void DrawControls();

		void DrawPauseMenu();

		void DrawDaniel();

		void Draw();


	private:

		int stageHandle[MAXSTAGES], coinHandle;
	    Quad stagePos[MAXSTAGES], coinPos[MAXSTAGES];
	    int stagesClear, animation;
	    int stageAnimation[MAXSTAGES], coinsTaken,coinsTaken2,coinsTaken3, coinsTakenSaved, coinsTakenSaved2, coinsTakenSaved3;
	    Coins* coins;
	    Player* player;
	    bool isPauseMenu;
	    bool stageFinished[3], stageCleared[3];
	    int controlsHandle;
	    int menuHandle1, menuHandle2;
	    int menuHandle;
	    bool isStage3Reached;
	    int cooldown;
	    int titleBGM;
	    int voiceHandle[1];
	    int menuAltHandle;
	    int altAnimation;




};
