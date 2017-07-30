#include "Bullet.h"
#include<DxLib.h>

Bullet::Bullet(const float& PosX, const float& PosY, const int& Num)
{
	PositionX = PosX;
	PositionY = PosY;
	VelocityY = -1;
	PositionNumber = Num;
	SetPos();

	speed = 15;
	radius = 7.5f;

	mHandle = LoadGraph("‰æ‘œ/Bullet.png");
	
	IsDelete = false;
}
Bullet::~Bullet()
{
	DeleteGraph(mHandle);
}

void Bullet::Update()
{
	CenterX = PositionX + 7.5f;
	CenterY = PositionY + 7.5f;

	SetVec();

	
	if (PositionY < 0) IsDelete = true;
}

void Bullet::Draw()
{
	if (PositionNumber == 1)  DrawGraph(PositionX, PositionY, mHandle, TRUE);
	else if (PositionNumber == 2) DrawRotaGraph(PositionX, PositionY,1,-195, mHandle, TRUE);
	else if (PositionNumber == 3) DrawRotaGraph(PositionX, PositionY, 1, 195, mHandle, TRUE);
	else if (PositionNumber == 4) DrawRotaGraph(PositionX, PositionY, 1, 75, mHandle, TRUE);
	else if (PositionNumber == 5) DrawRotaGraph(PositionX, PositionY, 1, -75, mHandle, TRUE);
	
}

void Bullet::SetVec()
{
	if (PositionNumber == 1)  VelocityX = 0;
	else if (PositionNumber == 2) VelocityX = -0.35f;
	else if (PositionNumber == 3) VelocityX = +0.35f;
	else if (PositionNumber == 4) VelocityX = -0.7f;
	else if (PositionNumber == 5) VelocityX = 0.7f;

	PositionX += VelocityX * speed;
	PositionY += VelocityY * speed;
}

void Bullet::SetPos()
{
	if (PositionNumber == 1) {
		PositionX += 22.5;
	}
	else if (PositionNumber == 2) {
		PositionX -= 0;
	}
	else if (PositionNumber == 3) {
		PositionX += 45;
	}
	else if (PositionNumber == 4) {
		PositionY += 32.5;
	}
	else if (PositionNumber == 5) {
		PositionX += 45;
		PositionY += 32.5;
	}
}


