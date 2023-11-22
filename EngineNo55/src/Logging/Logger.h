#pragma once

#include <spdlog/spdlog.h>
#include "Engine/Core.h"

namespace Number55{

	class ENGINE55_API Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return sEngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return sClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> sEngineLogger;
		static std::shared_ptr<spdlog::logger> sClientLogger;
	};

}

// Core Log Macros
#define EN55_CORE_TRACE(...)	::Number55::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define EN55_CORE_INFO(...)		::Number55::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define EN55_CORE_WARN(...)		::Number55::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define EN55_CORE_ERROR(...)	::Number55::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define EN55_CORE_FATAL(...)	::Number55::Logger::GetEngineLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define EN55_TRACE(...)			::Number55::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define EN55_INFO(...)			::Number55::Logger::GetClientLogger()->info(__VA_ARGS__)
#define EN55_WARN(...)			::Number55::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define EN55_ERROR(...)			::Number55::Logger::GetClientLogger()->error(__VA_ARGS__)
#define EN55_FATAL(...)			::Number55::Logger::GetClientLogger()->critical(__VA_ARGS__)
