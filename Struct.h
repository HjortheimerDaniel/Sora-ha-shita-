#pragma once
#define MAXBACKGROUNDS 5
#define MAXBACKGROUNDS2 5

struct Vector2 {
	float x, y;
};

struct Quad {
	Vector2 UL, UR, LL, LR;
};

struct PlayerStruct {
	Quad pos;
	Quad hitbox;
	Vector2 size;
	Vector2 hitboxSize;
	bool onGround;
	Vector2 velocity, acceleration, speed;
	int jumps, handle, idleHandle, walkingHandle, deathHandle, deathFrames, deathAnimation, direction, frames, animation, idleLeft;
	int reverseHandle, reverseHandleLeft;
	

};

struct MovingPlatform {
	Vector2 posStart,posEnd, size;
	bool goRight, goLeft;

};

struct Accessory {
	Quad pos;
	Vector2 size;
	bool isAcquired;
	int handle, timer, cooldownTimer;

};

struct Text {
	Quad pos;
	int frames;
	int animation;
	int handle;
	int handleHolder[6];
	int whichDialogue;
};

struct TitleStruct {
	Vector2 pos;
	int handle;
	int frames;
	int animation;
	bool keyPressed;
};

struct ClearStruct {
	Vector2 pos;
	int handle;
	int frames;
	int animation;
	Vector2 emitter;
	Vector2 emitterSize;
	int randX;
	int randY;
};
