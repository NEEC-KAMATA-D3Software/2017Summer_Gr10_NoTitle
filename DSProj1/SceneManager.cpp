#include "SceneManager.h"
#include"Title.h"
#include"GamePlay.h"
#include<DxLib.h>


SceneManager::SceneManager() :
	mNextScene(eScene_None)
{
	mScene = (BaseScene*) new Title(this);
}

void SceneManager::Start()
{
	mScene->Start();
}

void SceneManager::Finish()
{
	mScene->Finish();
}

void SceneManager::ChangeScene(eScene NextScnen)
{
	mNextScene = NextScnen;
}

void SceneManager::Update()
{
	if (mNextScene != eScene_None) {
		mScene->Finish();
		delete mScene;
		switch (mNextScene) {
		case eScene_Title:
			mScene = (BaseScene*) new Title(this);
			break;
		case eScene_GamePlay:
			mScene = (BaseScene*) new GamePlay(this);
			break;
		}
		mNextScene = eScene_None;

		mScene->Start();
	}

	mScene->Update();

}

void SceneManager::Draw()
{
	mScene->Draw();
}


