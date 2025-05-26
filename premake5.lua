workspace "Zote"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Zote"
	location "Zote"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ztpch.h"
	pchsource "Zote/src/ztpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"Zote/src"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ZT_PLATFORM_WINDOWS",
			"ZT_BUILD_DLL"
		}

		buildoptions
		{
			"/utf-8"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ZT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZT_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"

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
		"Zote/src",
		"Zote/vendor/spdlog/include"
	}

	links
	{
		"Zote"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ZT_PLATFORM_WINDOWS"
		}

		buildoptions
		{
			"/utf-8"
		}

	filter "configurations:Debug"
		defines "ZT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZT_DIST"
		optimize "On"