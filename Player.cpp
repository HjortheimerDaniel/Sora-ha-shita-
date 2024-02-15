#include "Player.h"

void Player::Initialize() {

	gravityButton->Initialize();
	floor->Initialize();
	xScroll->Initialize();
	player.pos.UL.x = 200;
	player.pos.UL.y = 430;
	player.pos.UR.x = 240;
	player.pos.UR.y = 430;
	player.pos.LL.x = 200;
	player.pos.LL.y = 470;
	player.pos.LR.x = 240;
	player.pos.LR.y = 470;

	player.hitbox.UL.x = 200;
	player.hitbox.UL.y = 430;
	player.hitbox.UR.x = 240;
	player.hitbox.UR.y = 430;
	player.hitbox.LL.x = 200;
	player.hitbox.LL.y = 470;
	player.hitbox.LR.x = 240;
	player.hitbox.LR.y = 470;

	player.size.x = 40;
	player.size.y = 40;
	player.onGround = false;
	player.acceleration.x = 0.0f;
	player.acceleration.y = 0.0f;
	player.velocity.x = 0.0f;
	player.velocity.y = 0.0f;
	player.handle = Novice::LoadTexture("./Sprites/Character.png");
	player.jumps = 1;
	gravityReverse = false;
	gravity = 1;
	player.speed.x = 0;
	player.speed.y = 0;
	gravityTimer = 0;
	hitHeadTimer = 0;
	isGravityChanged = false;
	dontShake = false;
	testVel.y = 0;
	hitHead = false;
	randX = 0;
	randY = 0;
	shake = false;
	seed = (unsigned int)time(nullptr);
	srand(seed);
	randStart = 30;
	randEnd = 14;
	shakeTimer = 0;
	playerSpiked = false;
	isTimeStopped = false;
	playerDead = false;

	for (int i = 0; i < MAXLines; i++) {

		newLineStart[i] = {0, 0};
		newLineEnd[i] = {0, 0};
	}
	for (int i = 0; i < MAXBLOCKS; i++) {
	
		newGravityUpButton[i] = { 0,0,};
		newGravityDownButton[i] = { 0,0,};
	}

	#pragma region Animation

	player.idleHandle = Novice::LoadTexture("./Sprites/Character.png");
	player.idleLeft = Novice::LoadTexture("./Sprites/CharacterLeft.png");
	player.reverseHandle = Novice::LoadTexture("./Sprites/CharacterReverse.png");
	player.reverseHandleLeft = Novice::LoadTexture("./Sprites/CharacterReverseLeft.png");
	player.handle = player.idleHandle;
	player.frames = 0;
	player.direction = 1;
	player.animation = 0;

#pragma endregion

	#pragma region Audio

	jumpAudio = Novice::LoadAudio("./Audio/Jump.wav");
	offScreenAudio = Novice::LoadAudio("./Audio/Fall.wav");
	voiceHandle = -1;
#pragma endregion

}

void Player::Initialize2() {
	gravityButton->Initialize2();
	floor->Initialize2();
	xScroll->Initialize();
	player.pos.UL.x = 200;
	player.pos.UL.y = 430;
	player.pos.UR.x = 240;
	player.pos.UR.y = 430;
	player.pos.LL.x = 200;
	player.pos.LL.y = 470;
	player.pos.LR.x = 240;
	player.pos.LR.y = 470;

	player.hitbox.UL.x = 200;
	player.hitbox.UL.y = 430;
	player.hitbox.UR.x = 240;
	player.hitbox.UR.y = 430;
	player.hitbox.LL.x = 200;
	player.hitbox.LL.y = 470;
	player.hitbox.LR.x = 240;
	player.hitbox.LR.y = 470;

	player.size.x = 40;
	player.size.y = 40;

	player.hitboxSize.x = 20;
	player.hitboxSize.y = 40;

	player.onGround = false;
	player.acceleration.x = 0.0f;
	player.acceleration.y = 0.0f;
	player.velocity.x = 0.0f;
	player.velocity.y = 0.0f;
	player.handle = Novice::LoadTexture("./Sprites/Character.png");
	player.jumps = 1;
	gravityReverse = false;
	gravity = 1;
	player.speed.x = 0;
	player.speed.y = 0;
	gravityTimer = 0;
	hitHeadTimer = 0;
	isGravityChanged = false;
	dontShake = false;
	testVel.y = 0;
	hitHead = false;
	randX = 0;
	randY = 0;
	shake = false;
	seed = (unsigned int)time(nullptr);
	srand(seed);
	randStart = 30;
	randEnd = 14;
	shakeTimer = 0;
	playerSpiked = false;
	theta = 0.0f;
	amplitude = 150;
	playerDead = false;

	for (int i = 0; i < MAXLines; i++) {

	newLineStart[i] = {0, 0};
	newLineEnd[i] = {0, 0};
	}
	for (int i = 0; i < MAXBLOCKS; i++) {

	newGravityUpButton[i] = {
		0,
		0,
	};
	newGravityDownButton[i] = {
		0,
		0,
	};

#pragma region Animation

	player.idleHandle = Novice::LoadTexture("./Sprites/Character.png");
	player.idleLeft = Novice::LoadTexture("./Sprites/CharacterLeft.png");
	player.reverseHandle = Novice::LoadTexture("./Sprites/CharacterReverse.png");
	player.reverseHandleLeft = Novice::LoadTexture("./Sprites/CharacterReverseLeft.png");
	player.deathHandle = Novice::LoadTexture("./Sprites/CharacterDead.png");
	player.handle = player.idleHandle;
	player.frames = 0;
	player.direction = 1;
	player.animation = 0;
	playerDeadAnimation = false;

#pragma endregion



#pragma region Audio

	jumpAudio = Novice::LoadAudio("./Audio/Jump.wav");
	offScreenAudio = Novice::LoadAudio("./Audio/Fall.wav");
	voiceHandle = -1;
#pragma endregion

	}
}

void Player::Initialize3() {

	gravityButton->Initialize3();
	floor->Initialize3();
	xScroll->Initialize();

	player.pos.UL.x = 200;
	player.pos.UL.y = 430;
	player.pos.UR.x = 240;
	player.pos.UR.y = 430;
	player.pos.LL.x = 200;
	player.pos.LL.y = 470;
	player.pos.LR.x = 240;
	player.pos.LR.y = 470;

	player.hitbox.UL.x = 200;
	player.hitbox.UL.y = 430;
	player.hitbox.UR.x = 240;
	player.hitbox.UR.y = 430;
	player.hitbox.LL.x = 200;
	player.hitbox.LL.y = 470;
	player.hitbox.LR.x = 240;
	player.hitbox.LR.y = 470;

	player.size.x = 40;
	player.size.y = 40;
	player.onGround = false;
	player.acceleration.x = 0.0f;
	player.acceleration.y = 0.0f;
	player.velocity.x = 0.0f;
	player.velocity.y = 0.0f;
	
	player.jumps = 1;
	gravityReverse = false;
	gravity = 1;
	player.speed.x = 0;
	player.speed.y = 0;
	gravityTimer = 0;
	hitHeadTimer = 0;
	isGravityChanged = false;
	dontShake = false;
	testVel.y = 0;
	hitHead = false;
	randX = 0;
	randY = 0;
	shake = false;
	seed = (unsigned int)time(nullptr);
	srand(seed);
	randStart = 30;
	randEnd = 14;
	shakeTimer = 0;
	playerSpiked = false;
	theta = 0.0f;
	amplitude = 150;
	playerDead = false;

	#pragma region Animation

	player.idleHandle = Novice::LoadTexture("./Sprites/Character.png");
	player.idleLeft = Novice::LoadTexture("./Sprites/CharacterLeft.png");
	player.reverseHandle = Novice::LoadTexture("./Sprites/CharacterReverse.png");
	player.reverseHandleLeft = Novice::LoadTexture("./Sprites/CharacterReverseLeft.png");
	player.handle = player.idleHandle;
	player.frames = 0;
	player.direction = 1;
	player.animation = 0;

	#pragma endregion

	for (int i = 0; i < MAXLines; i++) {

	newLineStart[i] = {0, 0};
	newLineEnd[i] = {0, 0};
	}
	for (int i = 0; i < MAXBLOCKS; i++) {

	newGravityUpButton[i] = {
		0,
		0,
	};
	newGravityDownButton[i] = {
		0,
		0,
	};
	}

	#pragma region AfterImages

	for (int i = 0; i < MAXAFTERIMAGES; i++) {
	isDraw[i] = 0;
	afterImageColor[i] = 0xFF0000FF;
	A[i] = 0x000000F8;
	afterImagePos[i].x = {};
	afterImagePos[i].y = {};
	seeThroughAfterImage[i] = 0;
	invisible[i] = false;
	}
	timer = 0;
	endOfScreen = 0;

	#pragma endregion

	#pragma endregion

#pragma region Audio

	jumpAudio = Novice::LoadAudio("./Audio/Jump.wav");
	offScreenAudio = Novice::LoadAudio("./Audio/Fall.wav");
	voiceHandle = -1;
#pragma endregion

}

void Player::Scroll() {

	theta += float(M_PI) / 300.0f;

	// scroll = xScroll->GetScroll();
	for (int i = 0; i < MAXLines; i++) {

	newLineStart[i].x = floor->GetLineStart()[i].x - xScroll->GetScroll().x;
	newLineEnd[i].x = floor->GetLineEnd()[i].x - xScroll->GetScroll().x;
	newLineStart[i].y = floor->GetLineStart()[i].y;
	newLineEnd[i].y = floor->GetLineEnd()[i].y;
	}



	for (int i = 0; i < MAXBLOCKS; i++) {

	newGravityUpButton[i].x = gravityButton->GetBlockUpPos()[i].UL.x - xScroll->GetScroll().x;
	newGravityUpButton[i].y = gravityButton->GetBlockUpPos()[i].UL.y - xScroll->GetScroll().y;

	newGravityDownButton[i].x = gravityButton->GetBlockDownPos()[i].UL.x - xScroll->GetScroll().x;
	newGravityDownButton[i].y = gravityButton->GetBlockDownPos()[i].UL.y - xScroll->GetScroll().y;
	}
}

void Player::Tunneling() {

	Vector2 dist[MAXLines], endStart[MAXLines], normalize[MAXLines], distPF[MAXLines];
	float length[MAXLines], t[MAXLines], distance[MAXLines];

	for (int i = 0; i < MAXLines; i++) {

		dist[i].x = player.pos.UL.x - newLineStart[i].x;
		dist[i].y = player.pos.UL.y - newLineStart[i].y;
		endStart[i].x = newLineEnd[i].x - newLineStart[i].x;
		endStart[i].y = newLineEnd[i].y - newLineStart[i].y;

		length[i] = sqrtf(endStart[i].x * endStart[i].x + endStart[i].y * endStart[i].y);

		normalize[i].x = endStart[i].x / length[i];
		normalize[i].y = endStart[i].y / length[i];

		t[i] = (dist[i].x * normalize[i].x + dist[i].y * normalize[i].y) / length[i];

		t[i] = Clamp(t[i], 0, 1);

		distPF[i].x = (1.0f - t[i]) * newLineStart[i].x + t[i] * newLineEnd[i].x;
		distPF[i].y = (1.0f - t[i]) * newLineStart[i].y + t[i] * newLineEnd[i].y;

		distance[i] = sqrtf(
		    (player.pos.UR.x - distPF[i].x) * (player.pos.UR.x - distPF[i].x) +
		    (player.pos.UR.y - distPF[i].y) * (player.pos.UR.y - distPF[i].y));

		if (distance[i] < 57 /*&& distance[i] > 42*/ /*&& player.pos.UL.y <= floor->GetLineStart()[i].y*/ && player.velocity.y <= 0 &&
		    CheckCollision(player.pos.UL, newLineStart[i], player.size,
		        floor->GetLineSize()[i]) &&
		    !gravityReverse && !isGravityChanged && !hitHead) {
			
			player.acceleration.y = 0;
			player.velocity.y = 0;
			player.jumps = 1;
			player.pos.UL.y = floor->GetLineStart()[i].y - 40;
			player.pos.UR.y = floor->GetLineStart()[i].y - 40;
			player.pos.LL.y = floor->GetLineStart()[i].y;
			player.pos.LR.y = floor->GetLineStart()[i].y;

		}

		if (distance[i] < 57 && player.velocity.y >= 0 && CheckCollision(player.pos.UL, newLineStart[i], player.size, floor->GetLineSize()[i]) &&
		    gravityReverse && !isGravityChanged && !hitHead) {
			player.acceleration.y = 0;
			player.velocity.y = 0;
			player.jumps = 1;
			player.pos.UL.y = floor->GetLineStart()[i].y;
			player.pos.UR.y = floor->GetLineStart()[i].y;
			player.pos.LL.y = floor->GetLineStart()[i].y + 40;
			player.pos.LR.y = floor->GetLineStart()[i].y + 40;

		} 

		if (distance[i] < 57 && player.velocity.y >= 1 &&
		    CheckCollision(player.pos.UL, newLineStart[i], player.size, floor->GetLineSize()[i]) &&
		    !gravityReverse && !isGravityChanged) {
			player.jumps = 0;
			player.velocity.y = 0;

			hitHead = true;
			player.pos.UL.y = floor->GetLineStart()[i].y;
			player.pos.UR.y = floor->GetLineStart()[i].y;
			player.pos.LL.y = floor->GetLineStart()[i].y + 40;
			player.pos.LR.y = floor->GetLineStart()[i].y + 40;
		}

		if (distance[i] < 57 && player.velocity.y <= -1 &&
		    CheckCollision(player.pos.UL, newLineStart[i], player.size, floor->GetLineSize()[i]) &&
		    gravityReverse && !isGravityChanged) {
			player.jumps = 0;
			player.velocity.y = 0;
			hitHead = true;
			player.pos.UL.y = floor->GetLineStart()[i].y - 40;
			player.pos.UR.y = floor->GetLineStart()[i].y - 40;
			player.pos.LL.y = floor->GetLineStart()[i].y;
			player.pos.LR.y = floor->GetLineStart()[i].y;
		}
		

		

		/*if (player.pos.LL.x >= newLineEnd[i].x ||
		    player.pos.LR.x <= newLineStart[i].x) {
			player.onGround = false;
			
			
		}*/
		if (player.onGround) {
			player.acceleration.y = 0;
			player.velocity.y = 0;
		}

	}

	if (hitHead) {
		hitHeadTimer++;
	}

	if (hitHeadTimer >= 5) {
		hitHead = false;
		hitHeadTimer = 0;
	}
	

}

void Player::DeathAnimation() {

	if (playerDeadAnimation) {
		player.deathFrames++;
	}

	if (player.deathFrames >= 5) {
		player.deathAnimation++;
		player.deathFrames = 0;
	}

	if (player.deathAnimation >= 4) {
		player.deathAnimation = 4;
		player.deathFrames = 0;
	}

	if (!playerDead) {
		player.deathFrames = 0;
		player.deathAnimation = 0;
	}

}

void Player::PlayerDead() {
	
	if (player.pos.LL.y >= 720 && !gravityReverse) {
		playerDead = true;
		playerDeadAnimation = true;
	} else if (player.pos.UL.y <= 0 && gravityReverse) {
		playerDead = true;
		playerDeadAnimation = true;
	} 


	
}

void Player::PlayerShake() {

	if (playerDead || playerSpiked) {
		shake = true;
		if (voiceHandle == -1) {
			Novice::PlayAudio(offScreenAudio, false, 0.3f);
			voiceHandle = 0;
		}

	}

	if (shake) {
		shakeTimer++;
		randX = rand() % randStart - randEnd;
		randY = rand() % randStart - randEnd;
	} 
	
	if (shakeTimer >= 10 && shakeTimer <= 14) {
		randStart = 20;
		randEnd = 9;
	} else if (shakeTimer >= 15 && shakeTimer <= 40) {
		randStart = 14;
		randEnd = 6;
		
	}else {
		randX = 0;
		randY = 0;
	}


	}

void Player::AfterImages() {

	R = 0;
	G = 100;
	B = 180;
	for (int i = 0; i < MAXAFTERIMAGES; i++) {
		A[i] = 0x000000F8;
	}

	R <<= 24;
	G <<= 16;
	B <<= 8;

	for (int i = 0; i < MAXAFTERIMAGES; i++) {

		afterImageColor[i] = R + G + B + A[i];
	}

	for (int i = 0; i < MAXAFTERIMAGES; i++) {
		if (isDraw[i] == 1) {
			invisible[i] = true;
		}
	}
	for (int i = 0; i < MAXAFTERIMAGES; i++) {
		if (invisible[i]) {
			seeThroughAfterImage[i] -= 3;
		}
		if (seeThroughAfterImage[i] <= -245) {
			seeThroughAfterImage[i] = -245;
			invisible[i] = false;
		}
	}

	if (isTimeStopped) {
		timer++;
	} else {
		timer = 0;
		for (int i = 0; i < MAXAFTERIMAGES; i++) {
			isDraw[i] = false;
			seeThroughAfterImage[i] = 0;
			invisible[i] = false;
			afterImageColor[i] = 0xFF0000FF;

		}
	}

	if (timer == 6) {
		timer = 0;

		for (int i = 0; i < MAXAFTERIMAGES; i++) {
			if (!isDraw[i]) {
				afterImagePos[i].x = player.pos.UL.x - (i * endOfScreen);
				afterImagePos[i].y = player.pos.UL.y;
				isDraw[i] = true;
				break;
			}
		}
	}
}

void Player::HitBox() {

	player.hitbox.UL.x = player.pos.UL.x +10;
	player.hitbox.UL.y = player.pos.UL.y;
	player.hitbox.UR.x = player.pos.UR.x -10;
	player.hitbox.UR.y = player.pos.UR.y;
	player.hitbox.LL.x = player.pos.LL.x + 10;
	player.hitbox.LL.y = player.pos.LL.y;
	player.hitbox.LR.x = player.pos.LR.x - 10;
	player.hitbox.LR.y = player.pos.LR.y;

}

void Player::Audio(char* keys, char* preKeys) {

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && player.jumps != 0) {
	
		Novice::PlayAudio(jumpAudio, false, 0.04f);
	}

}

void Player::Jump(char* keys, char* preKeys) {

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && player.jumps != 0) {
		player.velocity.y = 14 * gravity;
		player.jumps = 0;
		player.onGround = false;
	}
	for (int i = 0; i < MAXLines; i++) {

		if (CheckCollision(
		        player.pos.UL, floor->GetLineStart()[i], player.size, floor->GetLineSize()[i]) &&
		        !gravityReverse && gravityTimer == 0 ||
		    CheckCollision(
		        player.pos.LL, floor->GetLineStart()[i], player.size, floor->GetLineSize()[i]) &&
		        gravityReverse && gravityTimer == 0) {
			player.jumps = 1;
		} else {
			player.jumps = 0;
		}
	}


	if (player.jumps == 0 || !player.onGround) {
		player.acceleration.y = -0.7f * gravity;
	}

	player.velocity.y += player.acceleration.y;

	if (player.velocity.y <= -10 /*&& player.jumps != 0*/ && !gravityReverse) {
		player.velocity.y = -10;
	}
	if (player.velocity.y >= 10 /*&& player.jumps != 0*/ && gravityReverse) {
		player.velocity.y = 10;
	}

	player.pos.UL.y -= player.velocity.y;
	player.pos.UR.y -= player.velocity.y;
	player.pos.LL.y -= player.velocity.y;
	player.pos.LR.y -= player.velocity.y;

}

void Player::Walk(char* keys, char* preKeys) {
	
		player.speed.x = 0;
		player.speed.y = 0;

		if (keys[DIK_D] && preKeys[DIK_D] && player.pos.UL.x <= 800 && !keys[DIK_A] &&
	        !preKeys[DIK_A]) {
			player.speed.x = +5;
		}

		if (keys[DIK_A] && preKeys[DIK_A] && player.pos.UL.x >= 0 && !keys[DIK_D] &&
	        !preKeys[DIK_D]) {
			player.speed.x = -5;
		    
		}
		if (keys[DIK_A] && preKeys[DIK_A] && xScroll->GetScroll().x != 0 &&
	        player.pos.UL.x <= 200 && !keys[DIK_D] && !preKeys[DIK_D]) {
			player.speed.x += 5;
		}

		/*if (keys[DIK_S] && preKeys[DIK_S]) {
			player.speed.y = +5;
		}

		if (keys[DIK_W] && preKeys[DIK_W]) {
			player.speed.y = -5;
		}*/
	

	float normalizeSpeed = sqrtf(player.speed.x * player.speed.x + player.speed.y * player.speed.y);
	if (normalizeSpeed != 0.0f) {
		player.speed.x /= normalizeSpeed;
		player.speed.y /= normalizeSpeed;
	}

	player.pos.UL.x += player.speed.x * 5;
	player.pos.UR.x += player.speed.x * 5;
	player.pos.LL.x += player.speed.x * 5;
	player.pos.LR.x += player.speed.x * 5;
	player.pos.UL.y += player.speed.y * 5;
	player.pos.UR.y += player.speed.y * 5;
	player.pos.LL.y += player.speed.y * 5;
	player.pos.LR.y += player.speed.y * 5;

}

void Player::Gravity([[maybe_unused]] char* keys, [[maybe_unused]] char* preKeys) {
	
	if (!gravityReverse) {
		gravity = 1;
	} else {
		gravity = -1;
	}
	for (int i = 0; i < MAXBLOCKS; i++) {

		if (/*keys[DIK_F] && !preKeys[DIK_F] && !gravityReverse ||*/
		    CheckCollision(player.pos.UL, newGravityUpButton[i], player.size,gravityButton->GetBlockUpSize()) && !gravityReverse && gravityTimer == 0) {
			gravityReverse = true;
			isGravityChanged = true;
		}

		if (/*keys[DIK_G] && !preKeys[DIK_G] && gravityReverse ||*/ CheckCollision(player.pos.UL, newGravityDownButton[i], player.size, gravityButton->GetBlockUpSize()) && gravityReverse&& gravityTimer == 0) {
			gravityReverse = false;
			
			isGravityChanged = true;
		}
	}

	if (isGravityChanged) {
		gravityTimer++;
	}

	if (gravityTimer >= 10) {
		isGravityChanged = false;
		gravityTimer = 0;
	}

}

void Player::Animation(char* keys, char* preKeys) {


	if (keys[DIK_A] && !keys[DIK_D] && !preKeys[DIK_D]) {
		player.direction = -1;
	}
	if (keys[DIK_D] && !keys[DIK_A] && !preKeys[DIK_A]) {
		player.direction = 1;
	}

	if (player.direction == -1 && !gravityReverse) {
		player.handle = player.idleLeft;
	} 
	else if(player.direction == -1 && gravityReverse) {
		player.handle = player.reverseHandleLeft;
	}
	else if (player.direction == 1 && !gravityReverse) {
		player.handle = player.idleHandle;
	} else if (player.direction == 1 && gravityReverse) {
		player.handle = player.reverseHandle;
	}

	player.frames++;

	if (player.frames >= 10) {
		player.animation++;
		player.frames = 0;
	}

	if (player.animation >= 2) {
		player.animation = 0;

	}

}

void Player::Movement(char* keys, char* preKeys) {
	if (!isTimeStopped) {

		Jump(keys, preKeys);
		Gravity(keys, preKeys);
	}
	Walk(keys, preKeys);
	
}

void Player::Update(char* keys, char* preKeys) {
	PlayerDead();
	Tunneling();
	HitBox();
	Audio(keys, preKeys);
	DeathAnimation();
	Movement(keys, preKeys);
	xScroll->Update(keys, preKeys);
	Animation(keys, preKeys);
	Scroll();
	floor->Update();
	
}

void Player::Update2(char* keys, char* preKeys) {
	PlayerDead();
	Tunneling();
	HitBox();
	Audio(keys, preKeys);
	DeathAnimation();
	Animation(keys, preKeys);
	if (!playerSpiked) {

		Movement(keys, preKeys);
	}
	xScroll->Update(keys, preKeys);
	Scroll();
	floor->Update2();

}

void Player::Update3(char* keys, char* preKeys) {

	PlayerDead();
	Tunneling();
	HitBox();
	Audio(keys, preKeys);
	DeathAnimation();
	Animation(keys, preKeys);
	if (!playerSpiked) {

		Movement(keys, preKeys);
	}
	xScroll->Update(keys, preKeys);
	Scroll();
	floor->Update3();
	AfterImages();
	
}

void Player::UpdatePlayerDead() {

	PlayerShake();

}

void Player::DrawAfterImages() {

	for (int i = 0; i < MAXAFTERIMAGES; i++) {
		if (isDraw[i] && isTimeStopped) {
			/*Novice::DrawSprite(
			    (int)afterImagePos[i].x, (int)afterImagePos[i].y, player.handle, 1,
			    1, 0.0f, afterImageColor[i] + seeThroughAfterImage[i]);*/

			Novice::DrawQuad(
			    (int)afterImagePos[i].x + randX, (int)afterImagePos[i].y + randY,
			    (int)afterImagePos[i].x + 40 + randX, (int)afterImagePos[i].y + randY,
			    (int)afterImagePos[i].x + randX, (int)afterImagePos[i].y + 40 + randY,
			    (int)afterImagePos[i].x + 40 + randX, (int)afterImagePos[i].y + 40 + randY, 0, 0, 40, 40,
			    player.handle, afterImageColor[i] + seeThroughAfterImage[i]);
		}
	}
}

void Player::DrawDeathAnimation() {

	Novice::DrawQuad(
	    (int)player.pos.UL.x + randX, (int)player.pos.UL.y + randY, (int)player.pos.UR.x + randX,
	    (int)player.pos.UR.y + randY, (int)player.pos.LL.x + randX, (int)player.pos.LL.y + randY,
	    (int)player.pos.LR.x + randX, (int)player.pos.LR.y + randY, 40 * player.deathAnimation, 0, 40,
	    40, player.handle, WHITE);

}

void Player::Draw() {
	DrawAfterImages();
	if (!playerDead) {

		Novice::DrawQuad(
		    (int)player.pos.UL.x + randX, (int)player.pos.UL.y + randY,
		    (int)player.pos.UR.x + randX, (int)player.pos.UR.y + randY,
		    (int)player.pos.LL.x + randX, (int)player.pos.LL.y + randY,
		    (int)player.pos.LR.x + randX, (int)player.pos.LR.y + randY, 40 * player.animation, 0,
		    40, 40, player.handle, WHITE);
	}
	if (playerDead) {

		DrawDeathAnimation();
	}

	//Novice::ScreenPrintf(0, 0, "posX %f", player.pos.UL.x);
	//Novice::ScreenPrintf(0, 20, "boxX %f", player.hitbox.UL.x);
}
