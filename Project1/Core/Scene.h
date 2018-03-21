#pragma once
#include <vector>

namespace scene {
	class Scene
	{
	public:
		Scene();
		virtual ~Scene();

		bool init();
		void update();
		void draw() const;
		bool shutdown();


		std::vector<class GameObject*> gameObjects;

	};
}

/// .h