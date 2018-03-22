#include "MainScene.h"
#include <iostream>


MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}

bool MainScene::init()
{
	std::cout << "Scene init" << std::endl;

	return true;
}

void MainScene::update()
{
	std::cout << "Scene update" << std::endl;
}

void MainScene::draw() const
{
	std::cout << "Scene draw" << std::endl;
}

bool MainScene::shutdown()
{
	return true;
}
