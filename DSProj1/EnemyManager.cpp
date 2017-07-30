#include "EnemyManager.h"
#include<list>
#include<iostream>
#include<algorithm>

EnemyManager::EnemyManager()
{
	Time = 5;
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::Update()
{
	Time--;
	if (Time == 0) {
		Enemys.emplace_back(std::make_shared<Enemy>(rand() % 920 + 1,-30, 8));
		Time = 5;
	}
	for (auto x : Enemys) {
		x->Update();
	}
	
	Enemys.remove_if([](std::shared_ptr<Enemy> Enemys) {
		return Enemys->IsDelete;
	});
}

void EnemyManager::Draw()
{
	for (auto x : Enemys) {
		x->Draw();
	}
}

void EnemyManager::Start()
{
}

void EnemyManager::CSVRead()
{
}
