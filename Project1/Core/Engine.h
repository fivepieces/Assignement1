#pragma once
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include "Input.h"

#define ENGINE_INIT_ERROR 1
#define ENGINE_SHUTDOWN_ERROR 2

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

		//TODO: move these to the window system
		//The window we'll be rendering to
		SDL_Window* window = NULL;

		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;

		//The image we will load and show on the screen
		SDL_Surface* picture = NULL;

		Input inputSystem;

	public:
		Engine(scene::Scene *s);
		~Engine();

		int init();
		int Run();


	private:

		void update();
		void draw() const;
		int shutdown();
	};
};
