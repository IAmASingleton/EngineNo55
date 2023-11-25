#include "e55pch.h"

#include "Logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Engine55 
{
	std::shared_ptr<spdlog::logger> Logger::sEngineLogger;
	std::shared_ptr<spdlog::logger> Logger::sClientLogger;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		sEngineLogger = spdlog::stdout_color_mt("EngineNo55");
		sEngineLogger->set_level(spdlog::level::trace);

		sClientLogger = spdlog::stdout_color_mt("App");
		sClientLogger->set_level(spdlog::level::trace);
	}
}