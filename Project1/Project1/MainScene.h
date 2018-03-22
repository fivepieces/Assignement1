#pragma once
#include "Scene.h"


class MainScene : public scene::Scene
{
public:
	MainScene();
	~MainScene();

	 bool init() override;
	 void update()override;
	 void draw() const override;
	 bool shutdown()override;

};
