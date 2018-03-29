#pragma once
#include "System.h"

namespace core {
	class Input : public System
	{
		bool quitRequested;
		bool m_leftPressed = false;
	public:
		Input();
		~Input();

		void update() override;

		bool isLeftPressed() const { return m_leftPressed; }

		inline bool QuitRequested()const { return quitRequested; }
	};
}
