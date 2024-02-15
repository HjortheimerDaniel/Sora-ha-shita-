#pragma once
#include "Struct.h"
#include "Player.h"
#include "Novice.h"

class TimeAccessory {

	public:

		void InitializeOnce();

		void Initialize(Player* playerr);

		void SetScrollXForward(bool X) { isScrollXForward = X; }

	    void SetScrollXBackward(bool X) { isScrollXBackward = X; }

		void SetCutscene(bool X) { startCutscene = X; };

		void CollisionPlayerAccessory();

		void StopTime(char* keys, char* preKeys);

		void StopTimeTimer();

		Player* GetPlayer() { return player; };

		bool GetCutscene() { return startCutscene; };

		void ScrollAccessory();

		void AccessoryTaken();

		void Animation();

		void DrawBar();

		void Update(char* keys, char* preKeys);

		void Draw();

	private:

		Accessory accessory;
	    Player* player;
	    Vector2 barPos[2], size[2];
	    int color[2], scrollSpeed, frames, animation;
	    bool isScrollXForward, isScrollXBackward, startCutscene, endCutscene;

};
