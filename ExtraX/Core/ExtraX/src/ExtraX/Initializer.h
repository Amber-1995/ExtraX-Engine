#pragma once
#ifndef EXTRAX_INITIALIZATION_H
#define EXTRAX_INITIALIZATION_H
#include <ExtraX/Common.h>
#include <ExtraX/Input.h>

namespace ExtraX
{
	template<GRAPHICS_LIB, WINDOW_LIB>
	class Initializer
	{
	public:
		static void Init()
		{
			Input::Init();
		}
	};

	template<>
	class Initializer<GRAPHICS_LIB::OpenGL,WINDOW_LIB::GLFW>
	{
	public:
		static void Init();
	};
}



#endif //!EXTRAX_INITIALIZATION_H