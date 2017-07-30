#pragma once
#include"Character.h"
class  Bullet: public Character
{
public:
	 Bullet(const float& PosX,const  float& PosY,const int& Num);
	 ~Bullet();
	 void Update() override;
	 void Draw() override;
	 void SetVec();
	 void SetPos();
	 
private:
	int mHandle;
	int PositionNumber;
};

 