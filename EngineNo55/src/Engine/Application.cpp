#include "e55pch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Engine55
{
	Application::Application()
	{
		mpWindow = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		mbActive = true;
		while (mbActive)
		{
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			mpWindow->OnUpdate();

		}
	}
}