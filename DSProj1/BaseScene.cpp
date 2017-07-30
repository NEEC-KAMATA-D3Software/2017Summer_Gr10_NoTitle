#include "BaseScene.h"
#include<DxLib.h>

BaseScene::BaseScene(Scene * Change) :
	mHandle(0), x(0), y(0)
{
	mSceneChange = Change;
}

void BaseScene::Finish()
{
	DeleteGraph(mHandle);
}

void BaseScene::Draw()
{
	DrawGraph(x, y, mHandle, FALSE);
}