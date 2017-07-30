#pragma once
#include"IScene.h"
#include"Scene.h"

class  BaseScene :public IScene
{
protected:
	int mHandle;
	Scene* mSceneChange;
	int x;
	int y;
public:
	BaseScene(Scene* Change);
	virtual ~BaseScene() {}
	virtual void Start() override {}
	virtual void Finish() override;
	virtual void Update() override {}
	virtual void Draw() override;
};


