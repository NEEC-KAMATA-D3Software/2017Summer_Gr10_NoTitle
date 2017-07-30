#pragma once
#include"Enemy.h"
#include<iostream>
#include<algorithm>
#include<list>
#include<memory>
#include<string>
class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	void Update();
	void Draw();
	void Start();
	void CSVRead();
private:
	std::list<std::shared_ptr<Enemy>> Enemys;
	std::string  csv[256];
 	int Time;
};

