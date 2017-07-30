#pragma once
#include"Character.h"
#include"PlayerColor.h"

class  Player:public Character
{
public:
	Player();
	~Player();
	void Start();
	void Move();
	void Update() override;
	void Draw() override;
	
private:
	int mHandle[8];
	int mHcount;
	PlayerColor*  Pc;
};


