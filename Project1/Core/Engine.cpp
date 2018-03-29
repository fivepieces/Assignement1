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
				
				Viewport->x = SCREEN_WIDTH/2;
				Viewport->y = SCREEN_HEIGHT/2;

				//this is the little rectangle with the picture
				Viewport->w = 282;
				Viewport->h = 214;

				
				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 213, 126, 23));
				
				picture = SDL_LoadBMP("hello_world.bmp");

				
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
		//inputSystem.update();

		SDL_Event e;

		while (SDL_PollEvent(&e) != 0)
		{

			switch (e.type)
			{

			case SDL_KEYDOWN:

				switch (e.key.keysym.sym)
				{
				//TALIS u said u wanted it to move, not how far ok pls be gentle. I will figure it out soon but im running out of time.
					//I know the issue is that im moving the picture and then breaking out of the case, but after that im not saving its new position
					//so when i go back into the case it uses the same variable as before so essentially I can only move 1 frame per direction
				case SDLK_LEFT:
					std::cout << "Left" << std::endl;
					SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 213, 126, 23));
					Viewport->x = SCREEN_WIDTH / 2 - 4;
					break;

				case SDL_KEYUP:
					std::cout << "Key Released" << std::endl;
					break;

				case SDLK_UP:
					std::cout << "Up" << std::endl;
					SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 213, 126, 23));
					Viewport->y = SCREEN_HEIGHT / 2 -4;
					break;

				case SDLK_DOWN:
					std::cout << "Down" << std::endl;
					SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 213, 126, 23));
					Viewport->y = SCREEN_HEIGHT / 2 + 4;
					break;

				case SDLK_RIGHT:
					std::cout << "Right" << std::endl;
					SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 213, 126, 23));
					Viewport->x = SCREEN_WIDTH / 2 + 4;
					break;

				//case SDL_QUIT:
					//quitRequested = true;
					//break;
				}



			}
			//TODO: ADD CODE TO MOVE THE PICTURE

		}

		SDL_BlitSurface(picture, NULL, screenSurface, Viewport);

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