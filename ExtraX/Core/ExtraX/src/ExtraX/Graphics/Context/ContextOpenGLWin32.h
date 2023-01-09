#pragma once
#ifndef EXTRAX_CONTECT_OPENGL_WIN32_H
#define EXTRAX_CONTECT_OPENGL_WIN32_H

#include <ExtraX/Graphics/Context/ContextOpenGL.h>
#include <ExtraX/Graphics/Window/WindowWin32.h>

namespace ExtraX::Graphics::Base
{
	template<>
	class Context<"OpenGL", "Win32"> : public ContextOpenGL
	{
	private:
		Window<"Win32">* _window;
		HDC _dc;
		HGLRC _rc;
	public:
		Context(Window<"Win32">* window);

		virtual ~Context();

		void SwapBuffers() override;

		void MakeCurrent();

		static Graphics::Context* Create(Graphics::Window* window);
	};
}

#endif // !EXTRAX_CONTECT_OPENGL_WIN32_H