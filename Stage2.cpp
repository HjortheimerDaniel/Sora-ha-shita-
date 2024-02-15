#include "Stage2.h"


void Stage2::Initialize(Coins* coinss) {
	InitializeWind();
	player->Initialize2();
	floor->Initialize2();
	gravity->Initialize2();
	xScroll->Initialize();
	stageClear->Initialize2();
	coins= coinss;
	spikes->Initialize();
	coins->Initialize2();
	BackgroundInitialize2();
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
	coinAudio = Novice::LoadAudio("./Audio/Coin.wav");
	voiceHandle = -1;
	voiceHandle1 = -1;
	voiceHandle2 = -1;
	BGM = Novice::LoadAudio("./Audio/Song1.mp3");
	BGM2 = Novice::LoadAudio("./Audio/Song2.mp3");
	volume[0] = 0.4f;
	volume[1] = 0.0f;
}

void Stage2::Music() {

	if (!player->GetGravityReverse() && !stageComplete) {
		if (!Novice::IsPlayingAudio(voiceHandle)) {
			// volume[0] = 0.5f;
			voiceHandle = Novice::PlayAudio(BGM, true, volume[0]);
		}
	}else {
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

void Stage2::Reset(char* keys) {

	if (keys[DIK_R] || restartTimer >= 30) {
		coins->SetPlayerFell(true);
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

void Stage2::ScrollStage(char* keys, char* preKeys) {

	if (player->GetPlayerPos().UL.x >= 800 && keys[DIK_D] && preKeys[DIK_D]) {
		floor->SetScrollXForward(true);
		gravity->SetScrollXForward(true);
		stageClear->SetScrollXForward(true);
		coins->SetScrollXForward(true);
		spikes->SetScrollXForward(true);
		BackgroundSetScrollXForward(true);
	} else {
		floor->SetScrollXForward(false);
		gravity->SetScrollXForward(false);
		stageClear->SetScrollXForward(false);
		coins->SetScrollXForward(false);
		spikes->SetScrollXForward(false);
		BackgroundSetScrollXForward(false);

	}

	if (player->GetPlayerPos().UL.x <= 200 && keys[DIK_A] && preKeys[DIK_A] &&
	    floor->GetLineStart()[0].x < 0) {
		floor->SetScrollXBackward(true);
		gravity->SetScrollXBackward(true);
		stageClear->SetScrollXBackward(true);
		coins->SetScrollXBackward(true);
		spikes->SetScrollXBackward(true);
		BackgroundSetScrollXBackward(true);
	} else {
		floor->SetScrollXBackward(false);
		gravity->SetScrollXBackward(false);
		stageClear->SetScrollXBackward(false);
		coins->SetScrollXBackward(false);
		spikes->SetScrollXBackward(false);
		BackgroundSetScrollXBackward(false);
	}
}

void Stage2::ScrollXSpeed() {
	if (scrollX < 5) {

		scrollX = xScroll->GetScroll().x;
	}
	gravity->SetScrollXSpeed(scrollX);
	stageClear->SetScrollXSpeed(scrollX);
	coins->SetScrollXSpeed(scrollX);
	BackgroundSetScrollXSpeed(scrollX);
}

void Stage2::CollisionPlayerEnd() {

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

void Stage2::CollisionPlayerCoin() {
	for (int i = 0; i < 3; i++) {
		if (CheckCollision(player->GetPlayerPos().UL, coins->GetCoinPos2()[i].UL, player->GetPlayerSize(), coins->GetCoinSize())) {
			coins->SetCoinTaken2(i, true);
			voiceHandle1 = Novice::PlayAudio(coinAudio, false, 0.2f);
		}
	}
}

void Stage2::CollisionPlayerSpikes() {
	for (int i = 0; i < MAXSPIKES; i++) {
		if(CheckCollision(
		        player->GetPlayerHitBoxPos().UL, spikes->GetSpikePos()[i], player->GetPlayerHitBoxSize(),
			spikes->GetSpikeSize()[i])) {
			player->SetPlayerSpiked(true);
		}
	}
	

}

void Stage2::BlackenScreen() {

	if (seeThrough <= 250) {
		seeThrough += 7;
	}

	if (seeThrough >= 250) {
		restartTimer++;
	}
}

void Stage2::Gravity() {

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

void Stage2::Update(char* keys, char* preKeys) {
	Reset(keys);
	if (!player->GetPlayerDead() && player->GetPlayerSpiked() == false) {
		player->Update2(keys, preKeys);
		gravity->Update();
		floor->Update2();
		coins->Update2();
		spikes->Update();
		stageClear->Update();
		xScroll->Update(keys, preKeys);
		ScrollStage(keys, preKeys);
		ScrollXSpeed();
		CollisionPlayerEnd();
		CollisionPlayerCoin();
		CollisionPlayerSpikes();
		Gravity();
		BackgroundUpdate2();
	}
	BlowWind();
	if (player->GetPlayerDead() == true || player->GetPlayerSpiked() == true) {
		player->UpdatePlayerDead();
		if (player->GetDeathTimer() >= 25) {
			BlackenScreen();
		}
	}
	Music();
	//Debug(keys, preKeys);
	
}

void Stage2::DrawBlackScreen() {

	if (player->GetDeathTimer() >= 25) {
		Novice::DrawBox(
		    (int)blackScreen.x, (int)blackScreen.y, 1280, 720, 0.0f, 0x00000000 + seeThrough,
		    kFillModeSolid);
	}
}

void Stage2::Draw() {
	BackgroundDraw2();
	DrawWind();
	gravity->Draw();
	player->Draw();
	spikes->Draw();
	floor->Draw2();
	stageClear->Draw();
	coins->Draw2();
	
	
	DrawBlackScreen();
	// P_RINT SEETHROUGH AND FIX DEATH THINGS
}

void Stage2::Debug(char* keys, char* preKeys) {

	if (keys[DIK_C] && !preKeys[DIK_C]) {
		stageComplete = true;
	}
}
