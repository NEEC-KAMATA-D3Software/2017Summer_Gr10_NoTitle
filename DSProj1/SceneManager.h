#pragma once
#include"BaseScene.h"
#include"Scene.h"
#include"IScene.h"

class  SceneManager :public Scene, IScene
{

private:
	BaseScene* mScene;
	eScene mNextScene;

public:
	SceneManager();
	void Start() override;
	void Update() override;
	void Draw() override;
	void Finish() override;

	void ChangeScene(eScene NextScnen) override;
};

