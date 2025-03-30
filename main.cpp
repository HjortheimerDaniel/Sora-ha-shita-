#include <Novice.h>
#include "Stages.h"

const char kWindowTitle[] = "GC1B_07_ジュットハイマー_ダニエル_空は。。下？";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	Stages* stage = new Stages();


	stage->Initialize(); //
	

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		stage->Update(keys, preKeys);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		stage->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete stage;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
