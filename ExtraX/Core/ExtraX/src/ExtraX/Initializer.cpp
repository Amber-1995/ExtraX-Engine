#include <XXPch.h>
#include <GLFW/glfw3.h>
#include "Initializer.h"


namespace ExtraX
{
	void Initializer<GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW>::Init()
	{
		Input::Init();
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
}