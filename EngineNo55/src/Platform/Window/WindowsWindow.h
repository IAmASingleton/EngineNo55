#pragma once
#include "e55pch.h"

#include "Engine/Window.h"

#include <GLFW/glfw3.h>

namespace Engine55
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return mData.mWidth; }
		inline unsigned int GetHeight() const override { return mData.mHeight; }

		// Attributes
		inline void SetEventCallback(const EventCallbackFunc& callback) override { mData.mEventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* mpWindow;

		struct WindowData
		{
			std::string mTitle;
			unsigned int mWidth, mHeight;
			bool mbVSync;

			EventCallbackFunc mEventCallback;
		};

		WindowData mData;
	}; 
}

