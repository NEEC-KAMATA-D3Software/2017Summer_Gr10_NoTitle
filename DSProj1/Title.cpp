#include "Title.h"
#include<DxLib.h>

Title::Title(Scene * change) :
	BaseScene(change)
{
}

void Title::Update()
{
	if (CheckHitKey(KEY_INPUT_A)) {
		mSceneChange->ChangeScene(eScene_GamePlay);
	}

	/*if (CheckHitKey(KEY_INPUT_UP)) {
	y -= 10;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
	y += 10;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
	x -= 10;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
	x += 10;
	}*/

}

void Title::Draw()
{
	BaseScene::Draw();
}

void Title::Start()
{
	mHandle = LoadGraph("‰æ‘œ/Title.png");
}

void Title::Finish()
{
}
