#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Number55
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
