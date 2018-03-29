#include "MainScene.h"
#include <Input.h>
#include <SystemManager.h>
#include <Engine.h>
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
	using namespace core;
	
	SystemManager* sm = core::SystemManager::GetInstance();
	System * someSystem = sm->GetSystem(core::SystemType::INPUT);
	Input* input = dynamic_cast<Input*>(someSystem);

	

	
}

void MainScene::draw() const
{
	//std::cout << "Scene draw" << std::endl;
}

bool MainScene::shutdown()
{
	return true;
}
