workspace "EngineNo55"
architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	IncludeDir = {}
	IncludeDir["GLFW"] = "EngineNo55/ext/GLFW/include"

	include "EngineNo55/ext/GLFW"
	
project "EngineNo55"
	location "EngineNo55"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "e55pch.h"
	pchsource "EngineNo55/src/e55pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/ext/spdlog/include/",
		"%{IncludeDir.GLFW}"	
	}
	
	links
	{
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"EN55_PLATFORM_WINDOWS",
		"EN55_BUILD_DLL",
		"_WINDLL",
		"_UNICODE",
		"UNICODE"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/GameApp")
	}
	
	filter "configurations:Debug"
		defines "EN55_DEBUG"
		symbols "On"
			
	filter "configurations:Release"
		defines "EN55_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "EN55_DISTRIBUTION"
		optimize "on"
		
project "GameApp"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"
	location "GameApp"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/EngineNo55/ext/spdlog/include/",
		"%{wks.location}/EngineNo55/src",
		"%{wks.location}/EngineNo55/ext"
	}

	links
	{
		"EngineNo55"
	}

	filter "system:windows"
		defines "EN55_PLATFORM_WINDOWS"
		systemversion "latest"

	filter "configurations:Debug"
		defines "EN55_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "EN55_RELEASE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "EN55_DISTRIBUTION"
		runtime "Release"
		optimize "on"