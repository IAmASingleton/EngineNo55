#include "e55pch.h"

#include "Application.h"
#include "Logging/Logger.h"

#include <GLFW/glfw3.h>

namespace Engine55
{
#define MAX_RGB 255.0

#define BIND_EVENT_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		mpWindow = std::unique_ptr<Window>(Window::Create());
		if (mpWindow != nullptr)
			mpWindow->SetEventCallback(BIND_EVENT_FUNC(onEvent));
	}

	Application::~Application()
	{

	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher eDispatcher(e);
		eDispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(onWindowClose));

		EN55_CORE_TRACE("{0}",e.ToString());
	}

	bool Application::onWindowClose(WindowCloseEvent& e)
	{
		mbActive = false;
		return true;
	}

	void Application::run()
	{
		mbActive = true;
		while (mbActive)
		{
			GLclampf r = 0.0 / MAX_RGB;
			GLclampf g = 71.0 / MAX_RGB;
			GLclampf b = 171.0 / MAX_RGB;
			GLclampf alpha = 1.0;
			glClearColor(r,g,b,alpha);
			glClear(GL_COLOR_BUFFER_BIT);
			mpWindow->OnUpdate();

		}
	}
}