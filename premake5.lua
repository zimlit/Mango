--[[
        Copyright 2022  Devin Rockwell

    This file is part of Mango.

    Mango is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Mango is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Mango.  If not, see <https://www.gnu.org/licenses/>.    
]]

workspace "Mango"
    architecture "x64"
    startproject "Sandbox"


    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Mango/vendor/GLFW/include"
IncludeDir["Glad"] = "Mango/vendor/Glad/include"
IncludeDir["ImGui"] = "Mango/vendor/imgui"

group "Dependencies"
	include "Mango/vendor/GLFW"
	include "Mango/vendor/Glad"
	include "Mango/vendor/imgui"

group ""

project "Mango"
    location "Mango"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mgpch.h"
    pchsource "Mango/src/mgpch.cpp"

    files
    {
        "%{prj.name}/src/Mango/**.h",
        "%{prj.name}/src/Mango/**.cpp",
        "%{prj.name}/src/mgpch.h",
        "%{prj.name}/src/mgpch.cpp",
        "%{prj.name}/src/Platform/OpenGL/**"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui"
    }

    defines
    {
        "GLFW_INCLUDE_NONE",
        "IMGUI_IMPL_OPENGL_LOADER_CUSTOM"
    }

    filter "system:linux"

        files
        {
            "%{prj.name}/src/Platform/Linux/**.cpp",
            "%{prj.name}/src/Platform/Linux/**.h",
        }

        links
        {
            "GL",
            "pthread",
        }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        files
        {
            "%{prj.name}/src/Platform/Windows/**.cpp",
            "%{prj.name}/src/Platform/Windows/**.h",
        }

        defines
        {
            "MG_PLATFORM_WINDOWS",
            "MG_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")        
        }

        links
        {
            "opengl32.lib"
        }

    filter "configurations:Debug"
        defines 
        {
            "MG_DEBUG",
        }
        
        symbols "On"
        runtime "Debug"


    filter "configurations:Release"
        defines "MG_RELEASE"
        optimize "On"
        runtime "Release"

    filter "configurations:Dist"
        defines "MG_DIST"
        optimize "On"
        runtime "Release"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Mango/src",
        "Mango/vendor/spdlog/include"
    }

    links
    {
        "Mango"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MG_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "MG_DEBUG"
        symbols "On"
        runtime "Debug"

    filter "configurations:Release"
        defines "MG_RELEASE"
        optimize "On"
        runtime "Release"

    filter "configurations:Dist"
        defines "MG_DIST"
        optimize "On"
        runtime "Release"