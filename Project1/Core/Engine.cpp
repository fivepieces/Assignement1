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

		//The image we will load and show on the screen
		SDL_Surface* picture = NULL;

		//The window we'll be rendering to
		SDL_Window* window = NULL;

		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;

		//Event Handler
		SDL_Event e;

		SDL_Rect offset;
		offset.x = 100;
		offset.y = 200;
		
		bool quiting = false;

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

				//Fill the surface color of what u want boi
				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 213, 126, 23));

				//Apply the image
				picture = SDL_LoadBMP("hello_world.bmp");
				SDL_BlitSurface(picture, NULL, screenSurface, NULL);

				//Update the surface
				SDL_UpdateWindowSurface(window);

				//Wait two seconds
				SDL_Delay(200000);
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