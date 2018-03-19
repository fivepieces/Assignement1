#include "Engine.h"
#include <iostream>
#include "Scene.h"

namespace core {

	Engine::Engine(scene::Scene* s) :
		mainScene(s)
	{
		mainScene = s;
	}


	Engine::~Engine()
	{

	}

	int Engine::init() {

		//The window we'll be rendering to
		SDL_Window* window = NULL;

		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;

		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Create window
			window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			}
			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);

				//Fill the surface white
				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

				//Update the surface
				SDL_UpdateWindowSurface(window);

				//Wait two seconds
				SDL_Delay(2000);
			}
		}
		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();

		mainScene->init();

		return 0;
	}




	int Engine::Run() {

		return 0;
	}
	void Engine::print() {

	}

	void Engine::update() {

		mainScene->update();
	}

	void Engine::draw() const {
		mainScene->draw();
	}

	int Engine::shutdown() {

		mainScene->shutdown();

		return 0;
	}
}