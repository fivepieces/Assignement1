#pragma once
#include "Manager.h"
#include <vector>
namespace core {

	std::vector<class System*> systems;
	class SystemManager : public Manager
	{
	public:
		SystemManager();
		~SystemManager();


		 bool init();
		 void update();
		 void draw() const;
		 bool shutdown();
	};

}

