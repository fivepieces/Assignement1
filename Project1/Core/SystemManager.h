#pragma once
#include "Manager.h"
#include <vector>
#include "System.h"
namespace core {

	
	class SystemManager : public Manager
	{
		std::vector<class System*> systems;
		SystemManager();

		static SystemManager* m_instance;
	public:
		
		~SystemManager();


		 bool init();
		 void update();
		 void draw() const;
		 bool shutdown();

		 static SystemManager* GetInstance()
		 {
			 if (m_instance == nullptr)
			 {
				 m_instance = new SystemManager;
			 }
			 return m_instance;
		 }

		 System* GetSystem(SystemType t) {
			 for (System* s : systems)
			 {
				 if (s->type == t) {
					 return s;
				 }
				 return nullptr;
			 }
		 }
	};

}

