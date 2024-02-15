#include "Stage3.h"

void Stage3::Initialize(Coins* coinss) {
	coins = coinss;
	player->Initialize3();
	floor->Initialize3();
	gravity->Initialize3();
	xScroll->Initialize();
	stageClear->Initialize3();
	coins->Initialize3();
	timeAccessory->Initialize(player);
	spikes->Initialize2();
	BackgroundInitialize3();
	distanceFP.x = 0;
	distanceFP.y = 0;
	normalize.x = 0;
	normalize.y = 0;
	fixDist.x = 0;
	fixDist.y = 0;
	scrollX = 0;
	stageComplete = false;
	blackScreen = {0, 0};
	seeThrough = 0;
	restartTimer = 0;
	stopTimeHandle = Novice::LoadTexture("./Sprites/StopTime.png");
	cutsceneHandle = Novice::LoadTexture("./Sprites/CutsceneText.png");
	
	#pragma region Wind

	InitializeWind();
	

	#pragma endregion

	#pragma region Text

	text.pos.UL.x = 430;
	text.pos.UL.y = 250;
	text.pos.UR.x = 630;
	text.pos.UR.y = 250;
	text.pos.LL.x = 430;
	text.pos.LL.y = 450;
	text.pos.LR.x = 630;
	text.pos.LR.y = 450;
	text.animation = 0;
	text.frames = 0;
	text.handleHolder[0] = Novice::LoadTexture("./Sprites/CutsceneText1.png");
	text.handleHolder[1] = Novice::LoadTexture("./Sprites/CutsceneText2.png");
	text.handleHolder[2] = Novice::LoadTexture("./Sprites/CutsceneText3.png");
	text.handleHolder[3] = Novice::LoadTexture("./Sprites/CutsceneText4.png");
	text.handleHolder[4] = Novice::LoadTexture("./Sprites/CutsceneText5.png");
	text.handleHolder[5] = Novice::LoadTexture("./Sprites/CutsceneText6.png");
	text.handle = text.handleHolder[0];
	text.whichDialogue = 0;
	cutsceneEndTimer = 0;
	cutsceneEnd = false;

	#pragma endregion
	coinAudio = Novice::LoadAudio("./Audio/Coin.wav");
	voiceHandle = -1;
	voiceHandle1 = -1;
	voiceHandle2 = -1;
	BGM = Novice::LoadAudio("./Audio/Song1.mp3");
	BGM2 = Novice::LoadAudio("./Audio/Song2.mp3");
	volume[0] = 0.4f;
	volume[1] = 0.0f;

}

void Stage3::InitializeOnce() {

	timeAccessory->InitializeOnce();

}

void Stage3::Reset(char* keys) {

	if (keys[DIK_R] || restartTimer >= 30) {
		coins->SetPlayerFell(true);
		player->SetIsTimeStopped(false);
		Novice::StopAudio(voiceHandle);
		Novice::StopAudio(voiceHandle2);
		volume[0] = 0.4f;
		volume[1] = 0.0f;
		Novice::SetAudioVolume(voiceHandle2, volume[1]);
		Novice::SetAudioVolume(voiceHandle, volume[0]);
		voiceHandle = -1;
		voiceHandle2 = -1;
		Initialize(coins);
	}
}

void Stage3::Music() {

	if (!player->GetGravityReverse()) {
		if (!Novice::IsPlayingAudio(voiceHandle) && !stageComplete) {
			// volume[0] = 0.5f;
			voiceHandle = Novice::PlayAudio(BGM, true, volume[0]);
		}
	} else {
		if (!Novice::IsPlayingAudio(voiceHandle2) && !stageComplete) {
			// volume[0] = 0.5f;
			voiceHandle2 = Novice::PlayAudio(BGM2, true, volume[1]);
		}
	}

	if (player->GetGravityReverse()) {
		volume[0] = 0.0f;

		if (Novice::IsPlayingAudio(voiceHandle)) {
			Novice::SetAudioVolume(voiceHandle, volume[0]);
		}
	} else {
		volume[0] = 0.4f;
		if (Novice::IsPlayingAudio(voiceHandle)) {
			Novice::SetAudioVolume(voiceHandle, volume[0]);
		}
	}
	if (player->GetGravityReverse()) {
		volume[1] = 0.4f;

		if (Novice::IsPlayingAudio(voiceHandle2)) {
			Novice::SetAudioVolume(voiceHandle2, volume[1]);
		}
	} else {
		volume[1] = 0.0f;
		if (Novice::IsPlayingAudio(voiceHandle2)) {
			Novice::SetAudioVolume(voiceHandle2, volume[1]);
		}
	}

}

void Stage3::ScrollStage(char* keys, char* preKeys) {

	if (player->GetPlayerPos().UL.x >= 800 && keys[DIK_D] && preKeys[DIK_D]) {
		isScrollXForwardWind = true;
		floor->SetScrollXForward(true);
		gravity->SetScrollXForward(true);
		stageClear->SetScrollXForward(true);
		coins->SetScrollXForward(true);
		spikes->SetScrollXForward(true);
		timeAccessory->SetScrollXForward(true);
		player->SetEndOfScreen(15);
		BackgroundSetScrollXForward(true);

	} else {
		isScrollXForwardWind = false;
		floor->SetScrollXForward(false);
		gravity->SetScrollXForward(false);
		stageClear->SetScrollXForward(false);
		coins->SetScrollXForward(false);
		spikes->SetScrollXForward(false);
		timeAccessory->SetScrollXForward(false);
		BackgroundSetScrollXForward(false);

		

	}

	if (player->GetPlayerPos().UL.x <= 200 && keys[DIK_A] && preKeys[DIK_A] &&
	    floor->GetLineStart()[0].x < 0) {
		isScrollXBackwardWind = true;
		floor->SetScrollXBackward(true);
		gravity->SetScrollXBackward(true);
		stageClear->SetScrollXBackward(true);
		coins->SetScrollXBackward(true);
		spikes->SetScrollXBackward(true);
		timeAccessory->SetScrollXBackward(true);
		BackgroundSetScrollXBackward(true);
	} else {
		isScrollXBackwardWind = false;

		floor->SetScrollXBackward(false);
		gravity->SetScrollXBackward(false);
		stageClear->SetScrollXBackward(false);
		coins->SetScrollXBackward(false);
		spikes->SetScrollXBackward(false);
		timeAccessory->SetScrollXBackward(false);
		BackgroundSetScrollXBackward(false);
	}

	
	if (player->GetPlayerPos().UL.x >= 800 && keys[DIK_D] && preKeys[DIK_D]) {
		player->SetEndOfScreen(15);
	} 
	else if (player->GetPlayerPos().UL.x <= 200 && keys[DIK_A] && preKeys[DIK_A] &&
	    floor->GetLineStart()[0].x < 0) {
		player->SetEndOfScreen(-15);
	} else {
		player->SetEndOfScreen(0);
	}

}

void Stage3::ScrollXSpeed() {
	if (scrollX < 5) {

		scrollX = xScroll->GetScroll().x;
	}
	gravity->SetScrollXSpeed(scrollX);
	stageClear->SetScrollXSpeed(scrollX);
	coins->SetScrollXSpeed(scrollX);
	BackgroundSetScrollXSpeed(scrollX);
}

void Stage3::CollisionPlayerEnd() {

	if (CheckCollision(
	        player->GetPlayerPos().UL, stageClear->GetFinishPos().UL, player->GetPlayerSize(),
	        stageClear->GetFinishSize())) {
				Novice::StopAudio(voiceHandle);
				Novice::StopAudio(voiceHandle2);
				voiceHandle = -1;
				voiceHandle2 = -1;
				stageComplete = true;
	}
}

void Stage3::CollisionPlayerCoin() {
	for (int i = 0; i < 3; i++) {
		if (CheckCollision(
		        player->GetPlayerPos().UL, coins->GetCoinPos3()[i].UL, player->GetPlayerSize(),
		        coins->GetCoinSize())) {
			coins->SetCoinTaken3(i, true);
			voiceHandle1 = Novice::PlayAudio(coinAudio, false, 0.2f);

		}
	}
}

void Stage3::CollisionPlayerSpikes() {
	for (int i = 0; i < MAXSPIKESLONG; i++) {
		if (CheckCollision(
		        player->GetPlayerHitBoxPos().UL, spikes->GetSpikePos()[i], player->GetPlayerHitBoxSize(),
		        spikes->GetSpikeSize()[i])) {
			player->SetPlayerSpiked(true);
		}
		if (CheckCollision(
		        player->GetPlayerHitBoxPos().UL, spikes->GetSpikePosLong()[i],
		        player->GetPlayerHitBoxSize(),
		        spikes->GetSpikeSizeLong()[i])) {
			player->SetPlayerSpiked(true);
		}
	}
}

void Stage3::CollisionPlayerDeathCube() {

		for (int i = 0; i < MAXSQUARES; i++) {
		if (CheckCollision(
		        player->GetPlayerHitBoxPos().UL, spikes->GetSpikeBasePos()[i],
		        player->GetPlayerHitBoxSize(),
		        spikes->GetSpikeBaseSize())) {
			player->SetPlayerSpiked(true);
		}
		
	}

}

void Stage3::BlackenScreen() {

	if (seeThrough <= 250) {
		seeThrough += 7;
	}

	if (seeThrough >= 250) {
		restartTimer++;
	}
}

void Stage3::Cutscene(char* keys, char* preKeys) {
	if (timeAccessory->GetCutscene()) {
		text.frames++;
	}

	if (text.frames >= 7) {
		text.animation++;
		text.frames = 0;
	}

	switch (text.whichDialogue) {		

		case 0:

			if (text.animation >= 6) {
				text.animation = 4;
				text.frames = 0;
			}

		    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				text.whichDialogue = 1;
				text.animation = 0;
				break;
		    }
		    break;
		case 1:

			if (text.animation >= 25) {
				text.animation = 23;
				text.frames = 0;
		    }

		    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				text.whichDialogue = 2;
				text.animation = 0;
				break;
		    }
		    break;

		case 2:

			if (text.animation >= 18) {
				text.animation = 16;
				text.frames = 0;
		    }

		    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				text.whichDialogue = 3;
				text.animation = 0;
				break;
		    }
		    break;

		case 3:

			if (text.animation >= 32) {
				text.animation = 30;
				text.frames = 0;
		    }

		    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				text.whichDialogue = 4;
				text.animation = 0;
				break;
		    }
				break;

		case 4:

			if (text.animation >= 26) {
				text.animation = 24;
				text.frames = 0;
		    }

		    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				text.whichDialogue = 5;
				text.animation = 0;
				break;
		    }
				break;

		case 5:

			if (text.animation >= 12) {
				text.animation = 12;
				text.frames = 0;
		    }

		    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				cutsceneEnd = true;
		    }

			if (cutsceneEnd) {
			    cutsceneEndTimer++;
			}

			if (cutsceneEndTimer >= 5) {
			    timeAccessory->SetCutscene(false);
			    player->SetIsTimeStopped(false);
			    cutsceneEndTimer = 0;
			    break;
			    
			}

		    break;

	default:
		break;
	}
}

void Stage3::Gravity() {

	if (player->GetGravityReverse()) {
		isGravityReversed = true;
		// background->SetColor(RED);
		BackgroundSetReversed1(-1);
		BackgroundSetReversed2(1280);
		BackgroundSetReversed3(720);
	} else {
		isGravityReversed = false;
		// background->SetColor(WHITE);
		BackgroundSetReversed1(1);
		BackgroundSetReversed2(0);
		BackgroundSetReversed3(0);
	}

	if (player->GetGravityReverse()) {
		isGravityReversed = true;
	} else {
		isGravityReversed = false;
	}

	GravityReversed();

}


void Stage3::Update(char* keys, char* preKeys) {
	Reset(keys);
	if (timeAccessory->GetCutscene()) {

		Cutscene(keys, preKeys);
	}
	if (!player->GetPlayerDead() && player->GetPlayerSpiked() == false && !timeAccessory->GetCutscene()){
		//player->Update3(keys, preKeys);
		timeAccessory->Update(keys, preKeys);
		gravity->Update();
		floor->Update3();
		coins->Update3();
		spikes->Update2();
		stageClear->Update();
		xScroll->Update(keys, preKeys);
		ScrollStage(keys, preKeys);
		ScrollXSpeed();
		CollisionPlayerEnd();
		CollisionPlayerCoin();
		CollisionPlayerSpikes();
		CollisionPlayerDeathCube();
		Gravity();
		BackgroundUpdate3();
		
	}

	if (!player->GetIsTimeStopped() && !timeAccessory->GetCutscene()) {
		coins->RotatingCoinAnimation2();
		spikes->MovingSpikesLong();
		BlowWind();
		
	}

	if (player->GetPlayerDead() == true || player->GetPlayerSpiked() == true) {
		player->UpdatePlayerDead();
		if (player->GetDeathTimer() >= 25) {
			BlackenScreen();
		}
	}
	ScrollWind();
	Music();
	//Debug(keys, preKeys);
}

void Stage3::DrawBlackScreen() {

	if (player->GetDeathTimer() >= 25) {
		Novice::DrawBox(
		    (int)blackScreen.x, (int)blackScreen.y, 1280, 720, 0.0f, 0x00000000 + seeThrough,
		    kFillModeSolid);
	}
}

void Stage3::DrawStopTime() {

	if (player->GetIsTimeStopped() || timeAccessory->GetCutscene()) {
		Novice::DrawSprite(0, 0, stopTimeHandle, 1, 1, 0.0f, WHITE);
	}

}

void Stage3::DrawCutscene() {

		if (timeAccessory->GetCutscene()) {
		Novice::DrawQuad(
		    (int)text.pos.UL.x, (int)text.pos.UL.y,
		    (int)text.pos.UR.x, (int)text.pos.UR.y,
		    (int)text.pos.LL.x, (int)text.pos.LL.y,
		    (int)text.pos.LR.x, (int)text.pos.LR.y,
			200 * text.animation, 0, 200, 200, text.handleHolder[text.whichDialogue], WHITE);

		}

}

void Stage3::Draw() {
	BackgroundDraw3();
	DrawWind();
	gravity->Draw();
	floor->Draw3();
	stageClear->Draw();
	coins->Draw3();
	spikes->Draw2();
	DrawStopTime();
	player->Draw();
	timeAccessory->Draw();
	coins->DrawScore();
	DrawBlackScreen();
	DrawCutscene();
	// P_RINT SEETHROUGH AND FIX DEATH THINGS

	//Novice::ScreenPrintf(0, 60, "%d", text.whichDialogue);
}

void Stage3::Debug(char* keys, char* preKeys) {

	if (keys[DIK_C] && !preKeys[DIK_C]) {
		stageComplete = true;
	}
}
