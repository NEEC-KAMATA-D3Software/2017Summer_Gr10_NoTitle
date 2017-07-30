#pragma once
#include"Character.h"
#include"BulletManager.h"
#include"Enemy.h"
#include"Player.h"
#include<list>
#include<memory>
#include<iostream>
#include<algorithm>

class CharacterManager
{
public:
	CharacterManager();
	~CharacterManager();
	void Start();
	void Update();
	void Draw();
	void SetEnemy();
	void CheckCollision();
	bool IsGameOver();
private :
	std::list <std::shared_ptr<Enemy>>  Enemys;
	
	Player* player;
	BulletManager* Bul;
	int EnemySetTime;
	int BulletLevel;
};
