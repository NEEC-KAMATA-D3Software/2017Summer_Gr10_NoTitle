#pragma 
#include"Enemy.h"
#include"Bullet.h"
#include"Player.h"
#include<list>
#include<memory>
#include<iostream>
#include<algorithm>
class BulletManager
{
public:
	BulletManager();
	~BulletManager();
	void Start();
	void Draw();
	void Update(float PosX,float PosY);
	void CheckCollision(std::shared_ptr<Enemy> enemy);
	void BulletLevel1(float PosX, float PosY);
	void BulletLevel2(float PosX, float PosY);
	void BulletLevel3(float PosX, float PosY);
	int Exp;

private:
	int Level;
	int BulletDelatTime;
	int mBulletBarHandle;
	int mBBHandle[33];
	std::list <std::shared_ptr<Bullet>>  BulletMiddle;
	std::list <std::shared_ptr<Bullet>>  BulletLeft;
	std::list <std::shared_ptr<Bullet>>  BulletRight;
	std::list <std::shared_ptr<Bullet>>  BulletRightOblique;
	std::list <std::shared_ptr<Bullet>>  BulletLeftOblique;

};

