workspace "EngineNo55"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "EngineNo55"
	location "EngineNo55"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/ext/spdlog/include/"
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
	location "GameApp"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"EngineNo55/ext/spdlog/include/",
		"EngineNo55/src/"
	}

	links
	{
		"EngineNo55"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"EN55_PLATFORM_WINDOWS",
		"_WINDLL",
		"_UNICODE",
		"UNICODE"
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