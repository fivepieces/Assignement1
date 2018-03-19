#pragma once

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
	};
}