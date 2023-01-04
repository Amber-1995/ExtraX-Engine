#include <glad/glad.h>
#include <ExtraX/Assert.h>
#include "ContextOpenGLGLFW.h"

namespace ExtraX::Graphics::Base
{
	Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW>::Context(Window<WINDOW_LIB::GLFW>* window)
	{
		_window = window;

		glfwMakeContextCurrent(_window->GetHandle());

		int ret = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		XX_CORE_ASSERT(ret, "Failed to initialize GLAD");

		glViewport(0, 0, _window->GetWidth(), _window->GetHeight());
	}

	Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW>::~Context()
	{

	}

	void Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW>::SwapBuffers()
	{
		glfwSwapBuffers(_window->GetHandle());
	}

	void Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW>::MakeCurrent()
	{
		glfwMakeContextCurrent(_window->GetHandle());
	}
}