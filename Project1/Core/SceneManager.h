#pragma once
#include "Manager.h"
#include <vector>
namespace core {

	class SceneManager : public Manager
	{
	public:
		SceneManager();
		~SceneManager();

		std::vector<class Scene*> scenes;
	};

}

