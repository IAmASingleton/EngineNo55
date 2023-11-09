#pragma once

#include "Core.h"

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
