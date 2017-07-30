#include "GamePlay.h"
#include<DxLib.h>

GamePlay::GamePlay(Scene * change) :
	BaseScene(change)
{
	/*p = new Player();
	E = new EnemyManager();*/
	C = new CharacterManager();
}

void GamePlay::Update()
{
	if (C->IsGameOver()) {
		mSceneChange->ChangeScene(eScene_Title);
	}

	/*p->Update();
	E->Update();*/
	C->Update();
	
}

void GamePlay::Draw()
{
	BaseScene::Draw();
	
	/*E->Draw();
	p->Draw();*/
	C->Draw();
}


void GamePlay::Start()
{
	mHandle = LoadGraph("‰æ‘œ/GamePlay.png");
	/*p->Start();*/
	C->Start();
}

void GamePlay::Finish()
{
	/*delete p;
	delete E;*/
	C->~CharacterManager();
}
