#pragma once
#include "e55pch.h"

#ifdef EN55_PLATFORM_WINDOWS
	
extern Engine55::Application* Engine55::CreateApplication();

// moved the main to the Engine so it runs with any Game
// we want to develop further on
int main(int argc, char** argv)
{
	int x = 3;

	Engine55::Logger::Init();
	EN55_CORE_WARN("Initialized Logger!");
	EN55_INFO("Hello! Var={0}", x);

	auto* pApp = Engine55::CreateApplication();
	if (pApp != nullptr)
		pApp->run();
	delete pApp;
	return 0;
}

#else
#error EngineNo55 supports only Windows!

#endif // EN55_PLATFORM_WINDOWS