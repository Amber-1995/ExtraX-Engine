#pragma once
#ifndef EXTRAX_COMMON_H
#define EXTRAX_COMMON_H

namespace ExtraX
{
	enum class WINDOW_LIB
	{
		Win32,
		GLFW,
	};

	enum class GRAPHICS_LIB
	{
		DirectX11,
		DirectX12,
		OpenGL,
		Vulkan,
	};

	enum class MATHEMATICS_LIB
	{
		GLM,
	};

	enum class GUI_LIB
	{
		IMGUI,
	};
}



#if !defined(EXTRAX_DISABLED_WINDOWS) && defined(_WIN32)
	#define XX_DEBUGBREAK() __debugbreak()
#endif

#define XX_EXPAND_MACRO(x) x
#define XX_STRINGIFY_MACRO(x) #x

#ifdef USE_EXTRAX_SETTINGS
	#include <ExtraXSettings.h>
#else
	#include <ExtraX/DefaultSettings.h>
#endif // EXTRAX_SETTINGS

#endif // !EXTRAX_COMMON_H
