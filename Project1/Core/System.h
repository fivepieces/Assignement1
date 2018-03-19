#pragma once

namespace core
{
	enum class SystemType : unsigned __int8 {

		WINDOW,
		INPUT
	};

	class System
	{
	protected:
		SystemType type;
	public:
		System(SystemType st);
		virtual ~System();

		bool init();
		void update();
		void draw() const;
		bool shutdown();
	};
}