#include "Enemy.h"
#include<DxLib.h>
#include<math.h>



Enemy::Enemy(const float& posx, const float& posy,const float& Speed)
{
	PositionX = posx;
    PositionY = posy;
	speed = Speed;
	mhandle = LoadGraph("‰æ‘œ/Enemy.png");
	radius = 20;
	IsDelete = false;
	HP = 3;
}

Enemy::~Enemy()
{
	DeleteGraph(mhandle);
}

void Enemy::Update()
{
	CenterX = PositionX + 20;
	CenterY = PositionY + 20;
	PositionY += speed;

	if (PositionY > 960|| HP <= 0) IsDelete = true;
}

void Enemy::Draw()
{
	DrawGraph(PositionX,PositionY, mhandle, TRUE);
}




