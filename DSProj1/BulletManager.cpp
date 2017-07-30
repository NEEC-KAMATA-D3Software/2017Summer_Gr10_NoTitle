#include "BulletManager.h"
#include<DxLib.h>

BulletManager::BulletManager()
{
	mBulletBarHandle = LoadGraph("‰æ‘œ/BulletBar1.png");
	LoadDivGraph("‰æ‘œ/BulletBar2.png", 33, 33, 1, 6, 30, mBBHandle);
}

BulletManager::~BulletManager()
{
}

void BulletManager::Start()
{
	BulletDelatTime = 5;
	Exp = 0;
	Level = 1;
}

void BulletManager::Draw()
{
	for (auto x : BulletMiddle) x->Draw();
	for (auto x : BulletLeft) x->Draw();
	for (auto x : BulletRight) x->Draw();
	for (auto x : BulletRightOblique) x->Draw();
	for (auto x : BulletLeftOblique) x->Draw();

	for (int i = 0; i < Exp; i++)
	{
		float posx = 755 + i * 6;
		
		DrawGraph(posx, 1, mBBHandle[i], true);
	}
	DrawGraph(739, 1, mBulletBarHandle, true);

	
	
}

void BulletManager::Update(float PosX, float PosY)
{
	BulletDelatTime--;
	if (Level > 0)BulletLevel1(PosX, PosY);
	if (Level > 1)BulletLevel2(PosX, PosY);
	if (Level > 2)BulletLevel3(PosX, PosY);
	if (BulletDelatTime <= 0) BulletDelatTime = 5;

	if (Exp >= 33 && Level < 3) {
		Level++; 
		Level != 3 ? Exp = 0 : Exp=33;
	}
}

void BulletManager::CheckCollision(std::shared_ptr<Enemy> enemy)
{
	for (auto y : BulletMiddle) {
		if (!enemy->IsDelete && enemy->Collision(y)) {
			enemy->HP--;
			if (enemy->HP <= 0 && Level < 3)Exp++;
			y->IsDelete = true;
		}
	}

	for (auto y : BulletLeft) {
		if (!enemy->IsDelete && enemy->Collision(y)) {
			enemy->HP--;
			if (enemy->HP <= 0 && Level < 3)Exp++;
			y->IsDelete = true;
		}
	}

	for (auto y : BulletRight) {
		if (!enemy->IsDelete && enemy->Collision(y)) {
			enemy->HP--;
			if (enemy->HP <= 0 && Level < 3)Exp++;
			y->IsDelete = true;
		}
	}

	for (auto y : BulletLeftOblique) {
		if (!enemy->IsDelete && enemy->Collision(y)) {
			enemy->HP--;
			if (enemy->HP <= 0 && Level < 3)Exp++;
			y->IsDelete = true;
		}
	}

	for (auto y : BulletRightOblique) {
		if (!enemy->IsDelete && enemy->Collision(y)) {
			enemy->HP--;
			if (enemy->HP <= 0 && Level < 3)Exp++;
			y->IsDelete = true;
		}
	}
}

void BulletManager::BulletLevel1(float PosX, float PosY)
{
	if (BulletDelatTime <= 0) 
		BulletMiddle.emplace_back(std::make_shared<Bullet>
			(PosX, PosY, 1));

	for (auto x : BulletMiddle) x->Update();

	BulletMiddle.remove_if([](std::shared_ptr<Bullet> Bullets)
	{ return Bullets->IsDelete; });
}

void BulletManager::BulletLevel2(float PosX, float PosY)
{
	if (BulletDelatTime <= 0) {
		BulletLeft.emplace_back(std::make_shared<Bullet>
			(PosX, PosY, 2));

		BulletRight.emplace_back(std::make_shared<Bullet>
			(PosX, PosY, 3));
	}

	for (auto x : BulletLeft) x->Update();
	for (auto x : BulletRight) x->Update();

	
	BulletLeft.remove_if([](std::shared_ptr<Bullet> Bullets)
	{ return Bullets->IsDelete; });
	BulletRight.remove_if([](std::shared_ptr<Bullet> Bullets)
	{ return Bullets->IsDelete; });
}

void BulletManager::BulletLevel3(float PosX, float PosY)
{
	if (BulletDelatTime <= 0) {
		BulletLeftOblique.emplace_back(std::make_shared<Bullet>
			(PosX, PosY, 4));

		BulletRightOblique.emplace_back(std::make_shared<Bullet>
			(PosX, PosY, 5));
	}

	for (auto x : BulletLeftOblique) x->Update();
	for (auto x : BulletRightOblique) x->Update();


	BulletLeftOblique.remove_if([](std::shared_ptr<Bullet> Bullets)
	{ return Bullets->IsDelete; });
	BulletRightOblique.remove_if([](std::shared_ptr<Bullet> Bullets)
	{ return Bullets->IsDelete; });
}

