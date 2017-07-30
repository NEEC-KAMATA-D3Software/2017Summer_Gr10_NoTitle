#pragma once
#include"Character.h"
#include"Bullet.h";
class  Enemy: public Character
{
public:
	Enemy(const float& posx, const float& posy,const float& speed);
	~ Enemy();
	void Update() override;
	void Draw()override;
	int HP;

private:
	int mhandle;
	
};

 