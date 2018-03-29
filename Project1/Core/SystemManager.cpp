#include "SystemManager.h"
#include "System.h"
#include "Input.h"
#include "Window.h"

namespace core {

	SystemManager* SystemManager::m_instance = NULL;

	SystemManager::SystemManager()
	{

		systems.push_back(new Input());
		systems.push_back(new Window());
	}


	SystemManager::~SystemManager()
	{
	}

	bool SystemManager::init()
	{
		for (System* s : systems)
		{
			if (!s->init()) {
				return false;
			}
		}
		return true;
	}

	void SystemManager::update()
	{
		for (System* s : systems)
		{
			s->update();
		}
	}

	void SystemManager::draw() const
	{
		for (System* s : systems)
		{
			s->draw();
		}
	}

	bool SystemManager::shutdown()
	{
		for (System* s : systems)
		{
			s->shutdown();
		}
		return true;
	}


}