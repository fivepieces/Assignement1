#pragma once
#include "System.h"
namespace core {

	class SystemManager
	{
	public:
		SystemManager();
		~SystemManager();
		int getSystem(SystemType type);
	};

}

