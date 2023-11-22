#include <stdio.h>

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Logging/Logger.h"

namespace Number55
{
	Application::Application()
	{
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		bool bEnd = false;
		while (!bEnd)
		{
			WindowResizeEvent e(1200, 720);
			EN55_TRACE(e.ToString());

			bEnd = true;
		}
	}
}