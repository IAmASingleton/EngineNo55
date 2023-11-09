#pragma once

#include "Application.h"

#ifdef EN55_PLATFORM_WINDOWS
	
extern Number55::Application* Number55::CreateApplication();

int main(int argc, char** argv)
{
	auto* pApp = Number55::CreateApplication();
	if (pApp != nullptr)
		pApp->run();
	delete pApp;
	return 0;
}

#else
#error EngineNo55 supports only Windows!

#endif // EN55_PLATFORM_WINDOWS