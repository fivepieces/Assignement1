#pragma once
#include <vector>

namespace scene {
	class Scene
	{
	public:
		Scene();
		virtual ~Scene();

		virtual bool init();
		virtual void update();
		virtual void draw() const;
		virtual bool shutdown();


		std::vector<class GameObject*> gameObjects;

	};
}

/// .h