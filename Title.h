#pragma once
#include "Struct.h"
#include "Novice.h"

class Title {



	public:

		void TitleInitialize();

		void Animation();

		void KeyPressed(char* keys);

		void TitleUpdate(char* keys);

		void TitleDraw();


	protected:

		TitleStruct title;

};
