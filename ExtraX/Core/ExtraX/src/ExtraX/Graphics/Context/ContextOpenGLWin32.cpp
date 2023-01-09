#include <XXPch.h>
#include <Windows.h>
#include <glad/glad.h>
#include <ExtraX/Assert.h>
#include "ContextOpenGLWin32.h"

namespace ExtraX::Graphics::Base
{
	Context<"OpenGL", "Win32">::Context(Window<"Win32">* window)
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

	Context<"OpenGL", "Win32">::~Context()
	{

	}

	void Context<"OpenGL", "Win32">::SwapBuffers()
	{
		::SwapBuffers(_dc);
	}

	void Context<"OpenGL", "Win32">::MakeCurrent()
	{
		wglMakeCurrent(_dc, _rc);
	}

	Graphics::Context* Context<"OpenGL", "Win32">::Create(Graphics::Window* window)
	{
		Window<"Win32">* window_win32 = dynamic_cast<Window<"Win32">*>(window);
		
		XX_CORE_ASSERT(window_win32,"Window is not Win32");

		return new Context<"OpenGL", "Win32">(window_win32);
	}
}