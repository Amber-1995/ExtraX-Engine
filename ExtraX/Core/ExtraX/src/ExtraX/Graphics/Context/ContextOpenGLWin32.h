#pragma once
#ifndef EXTRAX_CONTECT_OPENGL_WIN32_H
#define EXTRAX_CONTECT_OPENGL_WIN32_H

#include <ExtraX/Graphics/Context/ContextOpenGL.h>
#include <ExtraX/Graphics/Window/WindowWin32.h>

namespace ExtraX::Graphics::Base
{
	template<>
	class Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::Win32> : public ContextOpenGL
	{
	private:
		Window<WINDOW_LIB::Win32>* _window;
		HDC _dc;
		HGLRC _rc;
	public:
		Context(Window<WINDOW_LIB::Win32>* window = GetSingleton<Window<WINDOW_LIB::Win32>>());

		virtual ~Context();

		void SwapBuffers() override;

		void MakeCurrent();

	};
}

#endif // !EXTRAX_CONTECT_OPENGL_WIN32_H