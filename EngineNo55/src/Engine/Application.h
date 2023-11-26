#pragma once
#include "e55pch.h"

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Engine55
{
	class ENGINE55_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	private:
		std::unique_ptr<Window> mpWindow;
		bool mbActive{false};
	};

	// To be defined in client
	Application* CreateApplication();
}
