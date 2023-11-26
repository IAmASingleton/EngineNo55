#include "e55pch.h"
#include "WindowsWindow.h"

#include "Logging/Logger.h"

namespace Engine55 
{
	static bool sbGLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}	
	
	WindowsWindow::~WindowsWindow()
	{	
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		mData.mTitle = props.mTitle;
		mData.mWidth = props.mWidth;
		mData.mHeight = props.mHeight;

		EN55_CORE_INFO("Creating window {0} ({1},{2})", props.mTitle, props.mWidth, props.mHeight);

		if (!sbGLFWInitialized)
		{
			int success = glfwInit();
			EN55_CORE_ASSERT(success, "Could not initialize GLFW!");
			
			sbGLFWInitialized = true;
		}

		mWindow = glfwCreateWindow((int)props.mWidth, (int)props.mHeight, mData.mTitle.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(mWindow);
		glfwSetWindowUserPointer(mWindow, &mData);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(mWindow);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(mWindow);
	}

	void WindowsWindow::SetVSync(bool bEnabled)
	{
		if (bEnabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		mData.mbVSync = bEnabled;
	}
	bool WindowsWindow::IsVSync() const
	{
		return mData.mbVSync;
	}
}