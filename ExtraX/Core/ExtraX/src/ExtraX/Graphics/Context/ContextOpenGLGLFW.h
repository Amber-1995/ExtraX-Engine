#pragma once
#ifndef EXTRAX_CONTECT_OPENGL_GLFW_H
#define EXTRAX_CONTECT_OPENGL_GLFW_H

#include <ExtraX/Graphics/Context/ContextOpenGL.h>
#include <ExtraX/Graphics/Window/WindowGLFW.h>

namespace ExtraX::Graphics::Base
{
	template<>
	class Context<"OpenGL", "GLFW"> : public ContextOpenGL
	{
	private:
		Window<"GLFW">* _window;
	public:
		Context(Window<"GLFW">* window);

		virtual ~Context();

		void SwapBuffers() override;

		void MakeCurrent();

		static Graphics::Context* Create(Graphics::Window* window);
	};
}

#endif // !EXTRAX_CONTECT_OPENGL_GLFW_H
