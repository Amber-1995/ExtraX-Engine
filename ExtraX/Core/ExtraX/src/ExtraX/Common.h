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
		ImGui,
	};

	enum class LOG_LIB
	{
		SpdLog,
	};
}



#if !defined(EXTRAX_DISABLED_WINDOWS) && defined(_WIN32)
	#define XX_DEBUGBREAK() __debugbreak()
#endif

#define XX_EXPAND_MACRO(x) x
#define XX_STRINGIFY_MACRO(x) #x



#endif // !EXTRAX_COMMON_H
