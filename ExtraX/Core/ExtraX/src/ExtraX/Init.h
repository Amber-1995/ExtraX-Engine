#pragma once
#ifndef EXTRAX_INIT_H
#define EXTRAX_INIT_H

#include <ExtraX/Common.h>
#include <ExtraX/Input.h>

#if !defined(EXTRAX_DISABLE_GLFW)
	#include <GLFW/glfw3.h>
#endif

namespace ExtraX
{
	void Init()
	{
		Input::Init();
#if !defined(EXTRAX_DISABLE_GLFW)
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		if constexpr (DEFAULT_GRAPHICS_LIB == GRAPHICS_LIB::OpenGL)
		{
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		}
#endif

		
	}

}





#endif // !EXTRAX_INIT_H
