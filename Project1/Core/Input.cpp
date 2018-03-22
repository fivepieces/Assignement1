#include "Input.h"
#include <SDL.h>
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
			if (e.type == SDL_QUIT)
			{
				quitRequested = true;
			}
		}

	}
}