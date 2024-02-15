#pragma once
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "StageSelect.h"
#include "Title.h"
#include "GameClear.h"
class Stages: public Title {

	public:

		enum Game { Title, StageSelection, Stages1, Stages2, Stages3, GameComplete };

		void Initialize();

		void Update(char* keys, char* preKeys);

		void StageClear(char* keys, char* preKeys);

		//void GameFinished(char* keys, char* preKeys);

		

		void DrawStageClear();

		void Draw();

	private:
	    StageSelect* stageSelect = new StageSelect();
		Stage1* stage1 = new Stage1();
		Stage2* stage2 = new Stage2();
		Stage3* stage3 = new Stage3();
	    GameClear* gameClear = new GameClear();
	    Game game;
	    bool stagesClear[3];
	    int stageClearHandle;
	    int titleBGM;
	    int clearBGM;
	    int voiceHandle[2];

	   


};
