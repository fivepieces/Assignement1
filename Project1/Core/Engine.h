#pragma once
#include <SDL.h>
#include <stdio.h>
#include <vector>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

namespace scene {

	class Scene;

}
namespace core
{
	class Engine
	{
	private:
		bool isRunning;
		std::vector<class Manager*> managers;

		scene::Scene* mainScene;

	public:
		Engine(scene::Scene *s);
		~Engine();

		int init();
		int Run();
		void print();


	private:

		void update();
		void draw() const;
		int shutdown();
	};
};
