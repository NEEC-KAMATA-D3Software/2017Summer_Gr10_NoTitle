#pragma once
#include"BaseScene.h"
#include"Player.h"
#include"EnemyManager.h"
#include"CharacterManager.h"

class  GamePlay :public BaseScene
{
public:
	GamePlay::GamePlay(Scene* change);
	void Start() override;
	void Finish() override;
	void Update() override;
	void Draw() override;

private :
	Player*  p;
	EnemyManager* E;
	CharacterManager* C;
};

