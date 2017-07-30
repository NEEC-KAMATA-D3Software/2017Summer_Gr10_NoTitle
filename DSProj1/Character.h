#pragma once
#include<memory>
#include<iostream>
#include<algorithm>

class Character
{
public:
	Character() ;
	virtual ~Character() {}
	virtual void Update() {}
	virtual void Draw() {}
	virtual bool Collision(const std::shared_ptr<Character>& chara);
	bool IsDelete;
	float PositionX;
	float PositionY;

protected:
	int speed;
	float CenterX;
	float CenterY;
	float radius;
	float VelocityX;
	float VelocityY;
	

};

