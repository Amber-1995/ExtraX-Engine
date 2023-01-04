#pragma once
#include <ExtraX/Assert.h>
#include <ExtraX/Event.h>
#include <ExtraX/Input.h>
#include <ExtraX/Log.h>
#include <ExtraX/ResourceManager.h>
#include <ExtraX/Singleton.h>
#include <ExtraX/Initializer.h>

#include <ExtraX/Graphics/Window/WindowGLFW.h>
#include <ExtraX/Graphics/Context/ContextOpenGLGLFW.h>
#include <ExtraX/Graphics/Shader/ShaderOpenGL.h>


namespace ExtraX
{
	using Initializer = Base::Initializer<GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW>;

	namespace Graphics
	{
		using Window = Base::Window<WINDOW_LIB::GLFW>;
		using Context = Base::Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW>;
		using Shader = Base::Shader<GRAPHICS_LIB::OpenGL>;
	}
}