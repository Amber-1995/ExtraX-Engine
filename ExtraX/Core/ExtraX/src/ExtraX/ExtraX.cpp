#include <XXPch.h>
#include <GLFW/glfw3.h>
#include "ExtraX.h"


namespace ExtraX::Graphics
{
	Window* (*_XXCreateWindow)(int, int, const char*) = nullptr;

	Context* (*_XXCreateContext)(Window*) = nullptr;

	template<typename ...ARGS>
	Shader* (*_XXCreateShader)(Context*, ARGS...) =nullptr;

	Window* XXCreateWindow(int width, int height, const char* title)
	{
		return _XXCreateWindow(width, height, title);
	}

	Context* XXCreateContext(Window* window)
	{
		return _XXCreateContext(window);
	}

	template<>
	Shader* XXCreateShader<const char*, const char*>(Context* context, const char* arg1, const char*arg2)
	{
		return _XXCreateShader<const char*, const char*>(context, arg1, arg2);
	}
	template<>
	Shader* XXCreateShader<const char*, const char*, const char*>(Context* context, const char* arg1, const char* arg2, const char* arg3 )
	{
		return _XXCreateShader<const char*, const char*, const char*>(context, arg1, arg2, arg3);
	}
	template<>
	Shader* XXCreateShader<const char*, const char*, const char*, const char*>(Context* context, const char* arg1, const char* arg2, const char* arg3, const char* arg4)
	{
		return _XXCreateShader<const char*, const char*, const char*, const char*>(context, arg1, arg2, arg3, arg4);
	}
	template<>
	Shader* XXCreateShader<const char*, const char*, const char*, const char*, const char*>(Context* context, const char* arg1, const char* arg2, const char* arg3, const char* arg4, const char* arg5)
	{
		return _XXCreateShader<const char*, const char*, const char*, const char*, const char*>(context, arg1, arg2, arg3, arg4, arg5);
	}

}

namespace ExtraX
{



	template<>
	void Init<GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW>()
	{
		Input::Init();
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		Graphics::_XXCreateWindow = Graphics::Window::Create<WINDOW_LIB::GLFW>;

		Graphics::_XXCreateContext = Graphics::Context::Create<GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW>;

		Graphics::_XXCreateShader<const char*, const char*> = Graphics::Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*>;
		Graphics::_XXCreateShader<const char*, const char*, const char*> = Graphics::Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*, const char*>;
		Graphics::_XXCreateShader<const char*, const char*, const char*, const char*> = Graphics::Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*, const char*, const char*>;
		Graphics::_XXCreateShader<const char*, const char*, const char*, const char*, const char*> = Graphics::Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*, const char*, const char*, const char*>;

	}

	template<>
	void Init<GRAPHICS_LIB::OpenGL, WINDOW_LIB::Win32>()
	{
		Input::Init();

		Graphics::_XXCreateWindow = Graphics::Window::Create<WINDOW_LIB::Win32>;

		Graphics::_XXCreateContext = Graphics::Context::Create<GRAPHICS_LIB::OpenGL, WINDOW_LIB::Win32>;

		Graphics::_XXCreateShader<const char*, const char*> = Graphics::Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*>;
		Graphics::_XXCreateShader<const char*, const char*, const char*> = Graphics::Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*, const char*>;
		Graphics::_XXCreateShader<const char*, const char*, const char*, const char*> = Graphics::Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*, const char*, const char*>;
		Graphics::_XXCreateShader<const char*, const char*, const char*, const char*, const char*> = Graphics::Shader::Create<GRAPHICS_LIB::OpenGL, const char*, const char*, const char*, const char*, const char*>;

	}
}
