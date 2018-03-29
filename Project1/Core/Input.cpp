#include "Input.h"
#include <SDL.h>
#include <iostream>
#include "Engine.h"
namespace core {
	Input::Input() :
		System(SystemType::INPUT),
		quitRequested(false)
	{
	}

	Input::~Input()
	{
	}

	void Input::update()
	{
		SDL_Event e;

		while (SDL_PollEvent(&e) != 0)
		{
			
			switch (e.type)
			{
			
			case SDL_KEYDOWN:

				switch (e.key.keysym.sym) 
				{

				case SDLK_LEFT:
					std::cout << "Left" << std::endl;
					
					break;

				case SDL_KEYUP:
					std::cout << "Key Released" << std::endl;
					break;

				case SDLK_UP:
					std::cout << "Up" << std::endl;
					break;

				case SDLK_DOWN:
					std::cout << "Down" << std::endl;
					break;

				case SDLK_RIGHT:
					std::cout << "Right" << std::endl;
					break;

				case SDL_QUIT:
					quitRequested = true;
					break;
				}
			


			}
			//TODO: ADD CODE TO MOVE THE PICTURE

		}

	}
}