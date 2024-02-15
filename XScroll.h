#pragma once
#include "Struct.h"


class XScroll {

	public:

		void Initialize();

		void Update(char* keys, char* preKeys);

		void CameraScroll(char* keys, char* preKeys);

		Vector2 GetScroll() { return scroll; };

		//FIX SCROLL SO EVERYTHING EXCEPT PLAYER MOVES


	private:

		Vector2 scroll;
	    Vector2 playerPos;


};
