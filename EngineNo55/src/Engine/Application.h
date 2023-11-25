#pragma once
#include "e55pch.h"

#include "Core.h"
#include "Events/Event.h"

namespace Engine55
{
	class ENGINE55_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be defined in client
	Application* CreateApplication();
}
