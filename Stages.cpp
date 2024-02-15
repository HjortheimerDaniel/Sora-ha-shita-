#include "Stages.h"


void Stages::Initialize() {
	
	stage1->Initialize(); 
	
	stage2->Initialize(stage1->GetCoins()); 
	stage3->Initialize(stage2->GetCoins()); 
	stage3->InitializeOnce();
	stageSelect->Initialize(stage1->GetCoins(), stage1->GetPlayer());
	TitleInitialize();
	gameClear->Initialize();
	game = Title;
	for (int i = 0; i < 3; i++) {
		stagesClear[i] = false;
	}
	stageClearHandle = Novice::LoadTexture("./Sprites/StageClear.png");
	voiceHandle[0] = -1;
	voiceHandle[1] = -1;
	titleBGM = Novice::LoadAudio("./Audio/Title.mp3");
	clearBGM = Novice::LoadAudio("./Audio/GameClear.mp3");
}

void Stages::Update(char* keys, char* preKeys) {
	

	switch (game) {
	case Stages::Title:

		if (voiceHandle[0] == -1) {

			voiceHandle[0] = Novice::PlayAudio(titleBGM, true, 0.2f);
		}

		TitleUpdate(keys);

		if (title.keyPressed) {
			title.keyPressed = false;
			game = StageSelection;
			break;
		}

		break;

	case Stages::StageSelection:
		if (voiceHandle[0] == -1) {

			voiceHandle[0] = Novice::PlayAudio(titleBGM, true, 0.2f);
		}

		stageSelect->Update(keys, preKeys);
		stageSelect->Update2();
		stageSelect->Update3();
		

		if (keys[DIK_BACKSPACE] && preKeys[DIK_BACKSPACE]) {
			game = Title;
			break;
		}

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && stageSelect->GetStageAnimation()[0] == 0 && !stageSelect->GetIsPauseMenu()) {
			Novice::StopAudio(voiceHandle[0]);
			voiceHandle[0] = -1;
			game = Stages1;
			break;
		}

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && stageSelect->GetStageAnimation()[0] == 1 &&
		    (stageSelect->GetStagesClear() == 1 || stageSelect->GetStagesClear() == 2) &&
		    !stageSelect->GetIsPauseMenu()) {
			Novice::StopAudio(voiceHandle[0]);
			voiceHandle[0] = -1;
			game = Stages2;
			break;
		}
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && stageSelect->GetStageAnimation()[0] == 2 &&
		    (stageSelect->GetStagesClear() == 2 || stageSelect->GetStagesClear() == 3) &&
		    !stageSelect->GetIsPauseMenu()) {
			Novice::StopAudio(voiceHandle[0]);
			voiceHandle[0] = -1;
			game = Stages3;
			break;
		}

		
		break;

	case Stages::Stages1:

		if (!stagesClear[0]) {
			stage1->Update(keys, preKeys);
		}

		if (stage1->GetStageComplete() == true) {
			stageSelect->Update(keys, preKeys);
			stageSelect->SetStageFinished(true);
			stagesClear[0] = true;
			StageClear(keys, preKeys);
			break;
		}

		break;

	case Stages::Stages2:

		if (!stagesClear[1]) {
			stage2->Update(keys, preKeys);
		}
		if (stage2->GetStageComplete() == true) {
			stageSelect->Update2();
			stageSelect->SetStageFinished2(true);
			stagesClear[1] = true;
			StageClear(keys, preKeys);
			break;
		}

		break;

	case Stages::Stages3:

		stageSelect->SetIsStage3Reached(true);

		if (!stagesClear[2]) {
			stage3->Update(keys, preKeys);
		}
		if (stage3->GetStageComplete() == true) {
			stageSelect->Update3();
			stageSelect->SetStageFinished3(true);
			stagesClear[2] = true;
			StageClear(keys, preKeys);
			game = GameComplete;
			break;
		}

		break;

	case Stages::GameComplete:
		if (voiceHandle[1] == -1) {

			voiceHandle[1] = Novice::PlayAudio(clearBGM, true, 0.4f);
		}
		gameClear->Update();
		if (keys[DIK_SPACE]) {
			stage3->Initialize(stage1->GetCoins());
			stagesClear[2] = false;
			Novice::StopAudio(voiceHandle[1]);
			voiceHandle[1] = -1;
			game = StageSelection;
			break;
		}

		break;
	default:
		break;
	}
}

void Stages::StageClear(char* keys, char* preKeys) {

	#pragma region Stage1

	if (stagesClear[0] && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		stage1->Initialize();
		stagesClear[0] = false;
		game = Stages2;
		
	}

	if (stagesClear[0] && keys[DIK_R] && !preKeys[DIK_R]) {
		stage1->Initialize();
		stagesClear[0] = false;
		game = Stages1;
		
		
	}

	if (stagesClear[0] && keys[DIK_M] && !preKeys[DIK_M]) {
		stage1->Initialize();
		stagesClear[0] = false;
		game = StageSelection;
	}

	#pragma endregion

	#pragma region Stage2

	if (stagesClear[1] && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		stage2->Initialize(stage1->GetCoins());
		game = Stages3;
		stagesClear[1] = false;
	}

	if (stagesClear[1] && keys[DIK_R] && !preKeys[DIK_R]) {
		stage2->Initialize(stage1->GetCoins());
		game = Stages2;
		stagesClear[1] = false;
	}

	if (stagesClear[1] && keys[DIK_M] && !preKeys[DIK_M]) {
		stage2->Initialize(stage1->GetCoins());
		game = StageSelection;
		stagesClear[1] = false;
	}

	#pragma endregion

	#pragma region Stage3
	
 	if (stagesClear[2] && keys[DIK_SPACE] && !preKeys[DIK_SPACE] || game == GameComplete && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		stage3->Initialize(stage1->GetCoins());
		game = GameComplete;
		stagesClear[2] = false;
	}
	if (stagesClear[2] && keys[DIK_R] && !preKeys[DIK_R]|| game == GameComplete && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		stage3->Initialize(stage1->GetCoins());
		game = Stages3;
		stagesClear[2] = false;
	}
	if (stagesClear[2] && keys[DIK_M] && !preKeys[DIK_M]|| game == GameComplete && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		stage3->Initialize(stage1->GetCoins());
		game = StageSelection;
		stagesClear[2] = false;
	}

	#pragma endregion
}



void Stages::DrawStageClear() {

	if (stagesClear[0] || stagesClear[1] || stagesClear[2]) {
		Novice::DrawSprite(0, 0, stageClearHandle, 1, 1, 0.0f, WHITE);
	}

}

void Stages::Draw() {

	if (game == Title) {
		TitleDraw();
	}

	if (game == StageSelection) {
		stageSelect->Draw();
	}

	if (game == Stages1) {
		stage1->Draw();
		DrawStageClear();
		
	}

	if (game == Stages2) {
		stage2->Draw();
		DrawStageClear();
		
	}

	if (game == Stages3) {
		stage3->Draw();
		DrawStageClear();
		
	}

	if (game == GameComplete) {
		gameClear->Draw();
	}
}
