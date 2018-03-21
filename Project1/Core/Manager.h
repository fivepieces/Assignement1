#pragma once

namespace core {


	class Manager
	{
	public:
		Manager();
		~Manager();


		bool init();
		void update();
		void draw() const;
		bool shutdown();
	};

}


