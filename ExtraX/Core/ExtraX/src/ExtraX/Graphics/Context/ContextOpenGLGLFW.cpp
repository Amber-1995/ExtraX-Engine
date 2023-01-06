#include <XXPch.h>
#include <glad/glad.h>
#include <ExtraX/Assert.h>
#include <ExtraX/Graphics/Window/WindowGLFW.h>
#include "ContextOpenGLGLFW.h"


namespace ExtraX::Graphics
{
	template<>
	Context* Context::Create<GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW>(Window* window)
	{
		Base::Window<WINDOW_LIB::GLFW>*w = dynamic_cast<Base::Window<WINDOW_LIB::GLFW>*>(window);
		XX_CORE_ASSERT(w, "Window is not GLFW");

		return new Base::Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW>(w);
	}
}

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