#include <EngineNo55.h>

// This is our "Game"
class Game : public Number55::Application
{
public: 
	Game() {}
	~Game() {}

};

// This is the Entry Point into the Engine
Number55::Application* Number55::CreateApplication()
{
	return new Game();
}