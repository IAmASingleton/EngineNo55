#pragma once
#include "e55pch.h"

#include "Core.h"
#include "Events/Event.h"


namespace Engine55
{
	struct WindowProps
	{
		std::string mTitle;
		unsigned int mWidth;
		unsigned int mHeight;

		WindowProps(const std::string& title = "Engine Number 55",
			unsigned int width = 1280,
			unsigned int height = 720)
			: mTitle(title), mWidth(width), mHeight(height) {}
	};

	// abstract base class for windows
	class ENGINE55_API Window
	{
		public:
			using EventCallbackFunc = std::function<void(Event&)>;

			virtual ~Window() {}

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			// Attributes
			virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;

			static Window* Create(const WindowProps& props = WindowProps());
	
	};
}