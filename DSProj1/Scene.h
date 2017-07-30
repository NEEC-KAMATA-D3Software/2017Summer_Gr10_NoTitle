#pragma once
typedef enum
{
	eScene_Title,
	eScene_GamePlay,
	eScene_GameOver,
	eScene_None,
} eScene;

class  Scene
{
public:
	virtual ~Scene() = 0;
	virtual void ChangeScene(eScene NextScene) = 0;

};
