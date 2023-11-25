#include <EngineNo55.h>
#include <sstream>

// This is our "Game"
class Game : public Engine55::Application
{
public: 
	Game() {}
	~Game() {}
};

// This is the Entry Point into the Engine
Engine55::Application* Engine55::CreateApplication()
{
	return new Game();
}