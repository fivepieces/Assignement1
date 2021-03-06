#pragma once

namespace core
{
	enum class SystemType : unsigned __int8 {

		WINDOW,
		INPUT,
		TOTAL_SYSTEMS
	};

	class System
	{
	protected:
		
	public:
		SystemType type;
		System(SystemType st);
		virtual ~System();

		virtual bool init();
		virtual void update();
		virtual void draw() const;
		virtual bool shutdown();
	};
}