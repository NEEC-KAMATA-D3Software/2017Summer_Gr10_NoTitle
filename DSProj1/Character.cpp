#include "Character.h"
#include<math.h>
Character::Character()
{
	IsDelete = false;
}
bool Character::Collision(const std::shared_ptr<Character>& chara)
{
#ifdef _DEBUG
	auto myR = radius + chara->radius;

	auto otherR = hypotf(CenterX - chara->CenterX,
		CenterY - chara->CenterY);
#endif

	float a, b, c;
	a = CenterX - chara->CenterX;
	b = CenterY - chara->CenterY;
	c = radius + chara->radius;
	return c*c >= a*a + b*b ? true : false;

	
}