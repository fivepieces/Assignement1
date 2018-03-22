#pragma once
#include "System.h"

namespace core {
	class Input : public System
	{
		bool quitRequested;

	public:
		Input();
		~Input();

		void update() override;

		inline bool QuitRequested()const { return quitRequested; }
	};
}
