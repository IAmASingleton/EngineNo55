#include "e55pch.h"
#include "WindowsWindow.h"

#include "Logging/Logger.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace Engine55 
{
	static bool sbGLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		EN55_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

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
			glfwSetErrorCallback(GLFWErrorCallback);

			sbGLFWInitialized = true;
		}

		mpWindow = glfwCreateWindow((int)props.mWidth, (int)props.mHeight, mData.mTitle.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(mpWindow);
		glfwSetWindowUserPointer(mpWindow, &mData);
		SetVSync(true);

		//Set GLFW-callbacks
		glfwSetWindowSizeCallback(mpWindow, [](GLFWwindow* pWindow, int width, int height) {
			WindowData& rData = *(WindowData*)glfwGetWindowUserPointer(pWindow);
			rData.mWidth = width;
			rData.mHeight = height;
			WindowResizeEvent event(width, height);
			rData.mEventCallback(event);
			});

		glfwSetWindowCloseCallback(mpWindow, [](GLFWwindow* pWindow) {
			WindowData& rData = *(WindowData*)glfwGetWindowUserPointer(pWindow);
			WindowCloseEvent event;
			rData.mEventCallback(event);
			});

		glfwSetKeyCallback(mpWindow, [](GLFWwindow* pWindow, int key, int scancode, int action, int mods) {
			WindowData& rData = *(WindowData*)glfwGetWindowUserPointer(pWindow);
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					rData.mEventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					rData.mEventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					rData.mEventCallback(event);
					break;
				}
			}
			});
		glfwSetMouseButtonCallback(mpWindow, [](GLFWwindow* pWindow, int button, int action, int mods) {
			WindowData& rData = *(WindowData*)glfwGetWindowUserPointer(pWindow);
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					rData.mEventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					rData.mEventCallback(event);
					break; 
				}
			}
			});
		glfwSetScrollCallback(mpWindow, [] (GLFWwindow* pWindow, double offsetX, double offsetY){
			WindowData& rData = *(WindowData*)glfwGetWindowUserPointer(pWindow);

			MouseScrolledEvent event((float)offsetX,(float)offsetY);
			rData.mEventCallback(event);
			});

		glfwSetCursorPosCallback(mpWindow, [] (GLFWwindow* pWindow, double posX, double posY){
			WindowData& rData = *(WindowData*)glfwGetWindowUserPointer(pWindow);

			MouseMovedEvent event((float)posX,(float)posY);
			rData.mEventCallback(event);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(mpWindow);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(mpWindow);
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