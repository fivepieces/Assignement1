#include "Engine.h"
#include <iostream>
#include "Scene.h"
#include "SystemManager.h"

namespace core {


	Engine::Engine(scene::Scene* s) :
		mainScene(s),
		isRunning(false)
	{
		
	}


	Engine::~Engine()
	{

	}

	int Engine::init() {



		int initResult = 0;

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

			initResult = ENGINE_INIT_ERROR;
		}
		else
		{
			//Create window
			window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

				initResult = ENGINE_INIT_ERROR;
			}
			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);


			}
		}

		mainScene->init();

		return 0;
	}




	int Engine::Run() {
		isRunning = true;

		//Main game loop
		while (!inputSystem.QuitRequested())
		{
			//update
			update();

			//render
			draw();
		}

	
		return shutdown();
	}


	void Engine::update() {

		mainScene->update();
		inputSystem.update();

		//Fill the surface color of what u want boi
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 213, 126, 23));

		//Apply the image
		picture = SDL_LoadBMP("hello_world.bmp");
		SDL_BlitSurface(picture, NULL, screenSurface, NULL);

		//Update the surface
		SDL_UpdateWindowSurface(window);
	}

	void Engine::draw() const {
		mainScene->draw();
	}

	int Engine::shutdown() {

		if (!mainScene->shutdown())
		{
			return 1;
		}

		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();

		return 0;
	}
}