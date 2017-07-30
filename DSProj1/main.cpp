#include<DxLib.h>
#include"SceneManager.h"



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); SetGraphMode(960, 780, 16); DxLib_Init(); SetDrawScreen(DX_SCREEN_BACK);

	//Start
	

	SceneManager Scene;
	Scene.Start();


	//Update & Draw
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 ) {

		if (ProcessMessage() != 0) { // ���b�Z�[�W����
			break;//�E�B���h�E�́~�{�^���������ꂽ�烋�[�v�𔲂���
		}


		Scene.Update();
		Scene.Draw();


		ScreenFlip(); //����ʂ�\��ʂɔ��f
	}

	//Finish

	Scene.Finish();



	DxLib_End(); // DX���C�u�����I������
	return 0;


}