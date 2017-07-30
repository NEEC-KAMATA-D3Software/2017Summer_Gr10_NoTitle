#pragma once
class IScene
{
public:
	virtual ~IScene() {}
	virtual void Start() {}
	virtual void Finish() {}
	virtual void Update() = 0;
	virtual void Draw() = 0;

};

