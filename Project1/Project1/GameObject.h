#pragma once

namespace scene
{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();

		bool init();
		void update();
		void draw() const;
		bool shutdown();


	};

}
