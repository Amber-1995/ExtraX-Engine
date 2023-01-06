#include <XXPch.h>
#include <Windows.h>
#include <glad/glad.h>
#include <ExtraX/Assert.h>
#include "ContextOpenGLWin32.h"

namespace ExtraX::Graphics
{
	template<>
	Context* Context::Create<GRAPHICS_LIB::OpenGL, WINDOW_LIB::Win32>(Window* window)
	{
		Base::Window<WINDOW_LIB::Win32>* w = dynamic_cast<Base::Window<WINDOW_LIB::Win32>*>(window);
		XX_CORE_ASSERT(w, "Window is not Win32");

		return new Base::Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::Win32>(w);
	}
}

namespace ExtraX::Graphics::Base
{
	Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::Win32>::Context(Window<WINDOW_LIB::Win32>* window)
	{
		_window = window;
		_dc = GetDC(window->GetHandle());

		PIXELFORMATDESCRIPTOR pfd;
		ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
		pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pfd.nVersion = 1;
		pfd.cColorBits = 32;
		pfd.cDepthBits = 24;
		pfd.cStencilBits = 8;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;

		int format = ChoosePixelFormat(_dc, &pfd);

		SetPixelFormat(_dc, format, &pfd);

		_rc = wglCreateContext(_dc);

		wglMakeCurrent(_dc, _rc);

		int ret = gladLoadGL();

		XX_CORE_ASSERT(ret, "Failed to initialize GLAD");

		glViewport(0, 0, _window->GetWidth(), _window->GetHeight());
	}

	Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::Win32>::~Context()
	{

	}

	void Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::Win32>::SwapBuffers()
	{
		::SwapBuffers(_dc);
	}

	void Context<GRAPHICS_LIB::OpenGL, WINDOW_LIB::Win32>::MakeCurrent()
	{
		wglMakeCurrent(_dc, _rc);
	}
}