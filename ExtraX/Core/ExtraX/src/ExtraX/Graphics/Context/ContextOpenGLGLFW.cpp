#include <XXPch.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <ExtraX/Assert.h>
#include <ExtraX/Graphics/Window/WindowGLFW.h>
#include "ContextOpenGLGLFW.h"

namespace ExtraX::Graphics::Base
{
	Context<"OpenGL", "GLFW">::Context(Window<"GLFW">* window)
	{
		_window = window;

		glfwMakeContextCurrent(_window->GetHandle());

		int ret = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		XX_CORE_ASSERT(ret, "Failed to initialize GLAD");

		glViewport(0, 0, _window->GetWidth(), _window->GetHeight());
	}

	Context<"OpenGL", "GLFW">::~Context()
	{
	}

	void Context<"OpenGL", "GLFW">::SwapBuffers()
	{
		glfwSwapBuffers(_window->GetHandle());
	}

	void Context<"OpenGL", "GLFW">::MakeCurrent()
	{
		glfwMakeContextCurrent(_window->GetHandle());
	}

	Graphics::Context* Context<"OpenGL", "GLFW">::Create(Graphics::Window* window)
	{
		Window<"GLFW">* window_glfw = dynamic_cast<Window<"GLFW">*>(window);

		XX_CORE_ASSERT(window_glfw, "window is not GLFW");

		return new Context<"OpenGL", "GLFW">(window_glfw);
	}
}