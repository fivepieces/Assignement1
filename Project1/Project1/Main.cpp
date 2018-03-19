#include <Engine.h>
#include <iostream>
#include "MainScene.h"



int main(int argc, char* args[]) {

	using  namespace core;
	Engine e(new MainScene());

	if (e.init() != 0) {
		return e.Run();
	}


	return -1;
}