#include<DxLib.h>
#include"SceneManager.h"



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); SetGraphMode(960, 780, 16); DxLib_Init(); SetDrawScreen(DX_SCREEN_BACK);

	//Start
	

	SceneManager Scene;
	Scene.Start();


	//Update & Draw
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 ) {

		if (ProcessMessage() != 0) { // メッセージ処理
			break;//ウィンドウの×ボタンが押されたらループを抜ける
		}


		Scene.Update();
		Scene.Draw();


		ScreenFlip(); //裏画面を表画面に反映
	}

	//Finish

	Scene.Finish();



	DxLib_End(); // DXライブラリ終了処理
	return 0;


}