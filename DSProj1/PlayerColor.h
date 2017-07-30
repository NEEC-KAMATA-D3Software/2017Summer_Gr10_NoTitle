#pragma once
class PlayerColor
{
public:
	PlayerColor();
	~PlayerColor();
	void StartColor();
	void ColorChange();
	void Draw(const float& x,const float& y);

private:
	int mHandle[10];
	int i;
	int time;
};

