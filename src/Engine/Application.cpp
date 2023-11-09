#include <stdio.h>

#include "Application.h"

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
			printf("Welcome to Engine Number 55!\n");
			bEnd = true;
		}
	}
}