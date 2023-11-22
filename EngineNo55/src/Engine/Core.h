#pragma once

#ifdef EN55_PLATFORM_WINDOWS
	#ifdef EN55_BUILD_DLL
		// EXPORT-Macro for stuff compiled inside the DLL
		#define ENGINE55_API __declspec(dllexport)
	#else
		// IMPORT-Macro for stuff compiled outside the DLL
		#define ENGINE55_API __declspec(dllimport)
	#endif // EN55_BUILD_DLL
#else
#error EngineNo55 only supports Windows!

#endif // EN55_PLATFORM_WINDOWS

#define EN55_EXPAND_MACRO(x) x
#define EN55_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)