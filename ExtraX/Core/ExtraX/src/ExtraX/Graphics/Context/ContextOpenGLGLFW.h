#pragma once
#ifndef EXTRAX_CONTECT_OPENGL_GLFW_H
#define EXTRAX_CONTECT_OPENGL_GLFW_H

#include <ExtraX/Graphics/Context/ContextOpenGL.h>
#include <ExtraX/Graphics/Window/WindowGLFW.h>

namespace ExtraX::Graphics::Base
{
	template<>
	class Context< GRAPHICS_LIB::OpenGL, WINDOW_LIB::GLFW> : public ContextOpenGL
	{
	private:
		Window<WINDOW_LIB::GLFW>* _window;
	public:
		Context(Window<WINDOW_LIB::GLFW>* window = GetSingleton <Window<WINDOW_LIB::GLFW>>());

		virtual ~Context();

		void SwapBuffers() override;

		void MakeCurrent();
	};
}

#endif // !EXTRAX_CONTECT_OPENGL_GLFW_H
