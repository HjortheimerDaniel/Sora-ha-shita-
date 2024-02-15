#include "TimeAccessory.h"

void TimeAccessory::InitializeOnce() {

		accessory.isAcquired = false;
		startCutscene = false;
		endCutscene = false;
}

void TimeAccessory::Initialize(Player* playerr) {

	player = playerr;
	accessory.pos.UL.x = 560;
	accessory.pos.UL.y = 485;
	accessory.pos.UR.x = 575;
	accessory.pos.UR.y = 485;
	accessory.pos.LL.x = 560;
	accessory.pos.LL.y = 500;
	accessory.pos.LR.x = 575;
	accessory.pos.LR.y = 500;
	accessory.handle = Novice::LoadTexture("./Sprites/Ribbon.png");
	accessory.size.x = 15;
	accessory.size.y = 15;
	accessory.timer = 90;
	accessory.cooldownTimer = 0;
	barPos[0].x = 20;
	barPos[1].x = 21;
	barPos[0].y = 30;
	barPos[1].y = 31;
	size[0].x = 182;
	size[1].x = 180;
	size[0].y = 22;
	size[1].y = 19;
	color[0] = WHITE;
	color[1] = 0x00FF00FF;
	isScrollXBackward = false;
	isScrollXForward = false;
	scrollSpeed = 5;
	animation = 0;
	frames = 0;
}

void TimeAccessory::CollisionPlayerAccessory() {

	if (CheckCollision(accessory.pos.UL, player->GetPlayerPos().UL, accessory.size, player->GetPlayerSize()) && !endCutscene) {

		accessory.isAcquired = true;
		startCutscene = true;
		endCutscene = true;
		
	}
}

void TimeAccessory::StopTime(char* keys, char* preKeys) {

	if ((keys[DIK_LSHIFT] && !preKeys[DIK_LSHIFT] || keys[DIK_RSHIFT] && keys[DIK_RSHIFT]) && !player->GetIsTimeStopped() &&
	        accessory.isAcquired && accessory.timer == 90 /*||
	    keys[DIK_RSHIFT] && keys[DIK_RSHIFT]&& !player->GetIsTimeStopped() &&
	        accessory.isAcquired && accessory.timer == 90*/ ) {
			player->SetIsTimeStopped(true);
			player->SetAccY(0);
		    player->SetVelY(0);
		}
}

void TimeAccessory::StopTimeTimer() {

	if (player->GetIsTimeStopped()) {
		    accessory.timer--;    
	}

	if (accessory.timer <= 0) {
		    player->SetIsTimeStopped(false);
		    accessory.cooldownTimer++;
		  
	}
	if (accessory.cooldownTimer >= 50 && accessory.timer < 90 && !player->GetIsTimeStopped())  {
		    accessory.timer++;
		    
	}

	if (accessory.timer >= 90) {
		    accessory.cooldownTimer = 0;
	}

	if (accessory.timer >= 70) {
		    color[1] = 0x00FF00FF;
	} else if (accessory.timer >= 40 && accessory.timer < 70) {
		    color[1] = 0xEED202FF;
	} else {
		    color[1] = 0xDC143CFF;
	}
	

}

void TimeAccessory::ScrollAccessory() {

	if (isScrollXForward) {
		    accessory.pos.UL.x -= scrollSpeed;
		    accessory.pos.UR.x -= scrollSpeed;
		    accessory.pos.LL.x -= scrollSpeed;
		    accessory.pos.LR.x -= scrollSpeed;
	}
	if (isScrollXBackward) {
		    accessory.pos.UL.x += scrollSpeed;
		    accessory.pos.UR.x += scrollSpeed;
		    accessory.pos.LL.x += scrollSpeed;
		    accessory.pos.LR.x += scrollSpeed;
	}
}

void TimeAccessory::AccessoryTaken() {

	if (accessory.isAcquired && !player->GetGravityReverse()) {
		accessory.pos.UL.x = player->GetPlayerPos().UL.x + 20;
		accessory.pos.UL.y = player->GetPlayerPos().UL.y - 5;
		accessory.pos.UR.x = player->GetPlayerPos().UR.x -5;
		accessory.pos.UR.y = player->GetPlayerPos().UL.y - 5;
		accessory.pos.LL.x = player->GetPlayerPos().LL.x + 20;
		accessory.pos.LL.y = player->GetPlayerPos().LL.y - 30;
		accessory.pos.LR.x = player->GetPlayerPos().LR.x - 5;
		accessory.pos.LR.y = player->GetPlayerPos().LL.y - 30;
	}

	else if (accessory.isAcquired && player->GetGravityReverse()) {
		accessory.pos.UL.x = player->GetPlayerPos().UL.x;
		accessory.pos.UL.y = player->GetPlayerPos().UL.y + 25;
		accessory.pos.UR.x = player->GetPlayerPos().UR.x - 25;
		accessory.pos.UR.y = player->GetPlayerPos().UL.y + 25;
		accessory.pos.LL.x = player->GetPlayerPos().LL.x;
		accessory.pos.LL.y = player->GetPlayerPos().LL.y;
		accessory.pos.LR.x = player->GetPlayerPos().LR.x - 25;
		accessory.pos.LR.y = player->GetPlayerPos().LL.y ;
	}


}

void TimeAccessory::Animation() {

	frames++;

	if (frames >= 10 && frames <= 19) {
		animation = -1;
	}
	if (frames >= 20) {
		animation = 0;
		frames = 0;
	}
	if (accessory.isAcquired) {
		player->SetRandX(0);
		player->SetRandY(0);
	}
}

void TimeAccessory::DrawBar() {

	if (accessory.isAcquired) {
			Novice::DrawBox((int)barPos[0].x, (int)barPos[0].y, (int)size[0].x, (int)size[0].y, 0.0f, color[0],kFillModeWireFrame);
			Novice::DrawBox((int)barPos[1].x, (int)barPos[1].y, accessory.timer * 2, (int)size[1].y, 0.0f, color[1],kFillModeSolid);	
	}
}



void TimeAccessory::Update(char* keys, char* preKeys) {

	player->Update3(keys, preKeys);
	CollisionPlayerAccessory();
	AccessoryTaken();
	StopTime(keys, preKeys);
	StopTimeTimer();
	if (!accessory.isAcquired) {
		    ScrollAccessory();
	}

	if (accessory.isAcquired) {
		 Animation();
	}
	

}

void TimeAccessory::Draw() {

	Novice::DrawQuad(
	    (int)accessory.pos.UL.x + player->GetRandX(), (int)accessory.pos.UL.y + player->GetRandY(),
	    (int)accessory.pos.UR.x + player->GetRandX(), (int)accessory.pos.UR.y + player->GetRandY(),
	    (int)accessory.pos.LL.x + player->GetRandX(), (int)accessory.pos.LL.y + player->GetRandY(),
	    (int)accessory.pos.LR.x + player->GetRandX(), (int)accessory.pos.LR.y + player->GetRandY(),
	    0, 0, 15, 15, accessory.handle, 0xEED202FF);

	DrawBar();

	//Novice::ScreenPrintf(0, 0, "%d", accessory.isAcquired);

}
