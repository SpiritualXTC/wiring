
local ROOT = "../"
local SOURCE = ROOT .. "Source/"

workspace "Tutorial01_LED"

	language "C++"
	cppdialect "C++14"
	architecture "ARM"

	buildmessage 'TEST'
	
	configurations	{"Debug", "Release"}


	location( ROOT .. "_project_" )
	


	filter "configurations:Debug"	defines { "DEBUG" }		symbols 	"On"
	filter "configurations:Release"	defines { "NODEBUG" }	optimize	"On"

	filter {}

	targetdir "Bin/%{cfg.buildcfg}"
	objdir "Intermediate/%{cfg.buildcfg}"

	project "tut_01"
		kind "ConsoleApp"

		files
		{
			SOURCE .. "tut01_main.cpp"
		}

		links { "wiringPi" }

		filter { "system:not windows" }
			links { "ncurses" }

	project "tut_02"
		kind "ConsoleApp"

		files
		{
			SOURCE .. "tut02_main.cpp",
			SOURCE .. "main.cpp",
			SOURCE .. "curses.cpp",
		}
		
		links { "wiringPi" }

		filter { "system:not windows" }
			links { "ncurses" }
