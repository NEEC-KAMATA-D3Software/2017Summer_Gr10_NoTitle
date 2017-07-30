#pragma once
#include"BaseScene.h"
#include"Scene.h"

class Title :public BaseScene
{
public:
	Title(Scene* change);
	virtual void Finish();
	void Update() override;
	void Draw() override;
	void Start() override;
};
