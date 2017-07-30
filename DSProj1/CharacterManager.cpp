#include "CharacterManager.h"
#include"Bullet.h"
#include"Enemy.h"
#include<DxLib.h>


CharacterManager::CharacterManager()
{
	player = new Player();
	Bul = new BulletManager();
}

CharacterManager::~CharacterManager()
{
	delete Bul;
	delete player;
}

void CharacterManager::Start()
{
	EnemySetTime = 5;
	BulletLevel = 3;
	player->Start();
	Bul->Start();
}

void CharacterManager::Update()
{
	SetEnemy();
	player->Update();
	Bul->Update(player->PositionX, player->PositionY);
	CheckCollision();
}

void CharacterManager::Draw()
{
	for (auto x : Enemys) x->Draw();
	Bul->Draw();
	player->Draw();
}

void CharacterManager::SetEnemy()
{
	EnemySetTime--;
	if (EnemySetTime == 0) {
		Enemys.emplace_back(std::make_shared<Enemy>(rand() % 920 + 1, -30, 8));
		EnemySetTime = 5;
	}
	for (auto x : Enemys) x->Update();

	Enemys.remove_if([](std::shared_ptr<Enemy> Enemys) 
	{ return Enemys->IsDelete; });
}

void CharacterManager::CheckCollision()
{
	for (auto x : Enemys) {
		Bul->CheckCollision(x);
		if (player->Collision(x))player->IsDelete = true;
	}
}

bool CharacterManager::IsGameOver()
{
	return player->IsDelete;
}
