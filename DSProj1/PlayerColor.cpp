#include "PlayerColor.h"
#include<DxLib.h>

PlayerColor::PlayerColor()
{
	LoadDivGraph("‰æ‘œ/PlayerLine.png", 10, 10, 1, 60, 70, mHandle);
}

PlayerColor::~PlayerColor()
{
	for (int i = 0; i < 10; i++)
		DeleteGraph(mHandle[i]);
}

void PlayerColor::StartColor()
{
	i = 0;
	time = 10;
}

void PlayerColor::ColorChange()
{
	time--;
	if (time == 0) {
		i++;
		time = 10;
	}
	
	if (i == 9)i = 0;
}

void PlayerColor::Draw(const float& x,const float& y)
{
	DrawGraph((int)x, (int)y, mHandle[i],TRUE);
}