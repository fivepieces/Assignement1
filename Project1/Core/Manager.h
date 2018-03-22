#pragma once

namespace core {

	///Interfaces that define a manager
	//TODO: make this a singleton?
	class Manager
	{
	public:
		Manager();
		~Manager();


		virtual bool init() = 0;
		virtual void update() = 0;
		virtual void draw() const = 0;
		virtual bool shutdown() = 0;
	};

}


