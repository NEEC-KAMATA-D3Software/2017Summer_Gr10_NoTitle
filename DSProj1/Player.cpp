#include "Player.h"
#include<DxLib.h>
#include"PlayerColor.h"

Player::Player()
{
	Pc = new PlayerColor();
	LoadDivGraph("‰æ‘œ/Player.png", 8, 8, 1, 60, 80, mHandle);
	mHcount = 0;
	radius =28;
}

Player::~Player()
{
	

	for (int i = 0; i < 8; i++) {
		DeleteGraph(mHandle[i]);
	}
	delete Pc;
}

void Player::Start()
{
	PositionX = 100; PositionY = 100;
	speed = 10;
	Pc->StartColor();
}

void Player::Update()
{
	Move();

	CenterX = PositionX + 30;
	CenterY = PositionY + 30;

	mHcount++;
	if (mHcount == 7)mHcount = 0;

	Pc->ColorChange();
}

void Player::Draw()
{
	DrawGraph(PositionX, PositionY, mHandle[mHcount], TRUE);
	Pc->Draw(PositionX, PositionY);
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_UP) && PositionY > 0) {
		PositionY -= 1 * speed;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN) && PositionY < 710)
	{
		PositionY += 1 * speed;
	}

	if (CheckHitKey(KEY_INPUT_LEFT) && PositionX > 0)
	{
		PositionX -= 1 * speed;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) && PositionX < 900)
	{
		PositionX += 1 * speed;
	}
	

}