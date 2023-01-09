#include <XXPch.h>
#include <ExtraX/Event.h>
#include <ExtraX/Assert.h>
#include <ExtraX/Input.h>
#include <Windows.h>
#include <windowsx.h>
#include "WindowWin32.h"

namespace ExtraX::Graphics::Base
{
	Window<"Win32">::Window(WNDCLASSEX wcex, Descriptor descriptor)
	{
		_instance = wcex.hInstance;
		_class_name = wcex.lpszClassName;

		RegisterClassEx(&wcex);

		_hwnd = CreateWindowEx
		(
			descriptor.dwExStyle,
			descriptor.lpClassName,
			descriptor.lpWindowName,
			descriptor.dwStyle,
			descriptor.X,
			descriptor.Y,
			descriptor.nWidth,
			descriptor.nHeight,
			descriptor.hWndParent,
			descriptor.hMenu,
			descriptor.hInstance,
			descriptor.lpParam
		);

		XX_CORE_ASSERT(_hwnd, "Failed to create Win32 window");

		ShowWindow(_hwnd, SW_SHOW);
		UpdateWindow(_hwnd);
	}

	Window<"Win32">::Window(int width, int height, const char* title)
	{
#ifdef UNICODE
		std::wstring title_str(title, title + strlen(title));
#else
		std::string title_str(title);
#endif // UNICODE
		_instance = GetModuleHandle(NULL);

		auto window_process = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			switch (uMsg)
			{
			case WM_CLOSE:
				PostQuitMessage(0);
				DestroyWindow(hWnd);
				break;
			case WM_KEYDOWN:
			case WM_SYSKEYDOWN:
			case WM_IME_KEYDOWN:
			case WM_LBUTTONDOWN:
			case WM_RBUTTONDOWN:
			case WM_MBUTTONDOWN:
			case WM_XBUTTONDOWN:
			{
				EventInfo<EventType::KeyDown> event_keydown((int)wParam);
				EventManager::OnEvent(event_keydown);
			}
			break;
			case WM_KEYUP:
			case WM_SYSKEYUP:
			case WM_IME_KEYUP:
			{
				EventInfo<EventType::KeyUp> event_keyup((int)wParam);
				EventManager::OnEvent(event_keyup);
			}
			break;
			case WM_LBUTTONUP:
			{
				EventInfo<EventType::KeyUp> event_keyup(KeyCode::LeftMouseButton);
				EventManager::OnEvent(event_keyup);
			}
			break;
			case WM_RBUTTONUP:
			{
				EventInfo<EventType::KeyUp> event_keyup(KeyCode::RightMouseButton);
				EventManager::OnEvent(event_keyup);
			}
			break;
			case WM_MBUTTONUP:
			{
				EventInfo<EventType::KeyUp> event_keyup(KeyCode::MiddleMouseButton);
				EventManager::OnEvent(event_keyup);
			}
			break;
			case WM_XBUTTONUP:
				switch (GET_XBUTTON_WPARAM(wParam))
				{
				case XBUTTON1:
				{
					EventInfo<EventType::KeyUp> event_keyup(KeyCode::X1MouseButton);
					EventManager::OnEvent(event_keyup);
				}
				break;

				case XBUTTON2:
				{
					EventInfo<EventType::KeyUp> event_keyup(KeyCode::X2MouseButton);
					EventManager::OnEvent(event_keyup);
				}
				break;
				}
				break;

			case WM_MOUSEWHEEL:
			{
				EventInfo<EventType::MouseScrolled> event_mouse_scrolled(GET_WHEEL_DELTA_WPARAM(wParam) > 0 ? 1 : -1);
				EventManager::OnEvent(event_mouse_scrolled);
			}
			break;
			case WM_MOUSEMOVE:
			{
				EventInfo<EventType::MouseMoved> event_mouse_moved(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
				EventManager::OnEvent(event_mouse_moved);
			}
			break;
			}

			Win32CallBaceEventInfo event_call_back(hWnd, uMsg, wParam, lParam);
			EventManager::OnEvent(event_call_back);
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		};

		WNDCLASSEX wcex;
		ZeroMemory(&wcex, sizeof(WNDCLASSEXA));
		wcex.cbSize = sizeof(WNDCLASSEXA);
		wcex.style = CS_CLASSDC | CS_OWNDC;
		wcex.lpfnWndProc = window_process;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = _instance;
		wcex.hIcon = NULL;
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = _class_name.c_str();
		wcex.hIconSm = NULL;
		RegisterClassEx(&wcex);

		_hwnd = CreateWindowEx
		(
			0,
			_class_name.c_str(),
			title_str.c_str(),
			WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
			(GetSystemMetrics(SM_CXSCREEN) - width) / 2,
			(GetSystemMetrics(SM_CYSCREEN) - height) / 2,
			width + GetSystemMetrics(SM_CXDLGFRAME) * 2,
			height + GetSystemMetrics(SM_CYDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),
			NULL,
			NULL,
			GetModuleHandle(NULL),
			NULL
		);

		XX_CORE_ASSERT(_hwnd, "Failed to create Win32 window");

		ShowWindow(_hwnd, SW_SHOW);
		UpdateWindow(_hwnd);
	}

	Window<"Win32">::~Window()
	{
		UnregisterClass(_class_name.c_str(), _instance);

		DestroyWindow(_hwnd);
	}

	HWND Window<"Win32">::GetHandle()
	{
		return _hwnd;
	}

	bool Window<"Win32">::ShouldClose()
	{

		return _should_close;
	}

	void Window<"Win32">::FrameBegin()
	{
		MSG msg{};
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				_should_close = true;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		EventInfo<EventType::FrameBegin> event_frame_begin;
		EventManager::OnEvent(event_frame_begin);

	}

	void Window<"Win32">::FrameEnd()
	{
		EventInfo<EventType::FrameEnd> event_frame_end;
		EventManager::OnEvent(event_frame_end);
	}

	int Window<"Win32">::GetWidth()
	{
		RECT rect;
		GetWindowRect(_hwnd, &rect);
		return rect.right - rect.left - GetSystemMetrics(SM_CXDLGFRAME) * 2;
	}

	int Window<"Win32">::GetHeight()
	{
		RECT rect;
		GetWindowRect(_hwnd, &rect);
		return rect.bottom - rect.top - GetSystemMetrics(SM_CYDLGFRAME) * 2 - GetSystemMetrics(SM_CYCAPTION);
	}

	int Window<"Win32">::GetPositionX()
	{
		RECT rect;
		GetWindowRect(_hwnd, &rect);
		return rect.left;
	}

	int Window<"Win32">::GetPositionY()
	{
		RECT rect;
		GetWindowRect(_hwnd, &rect);
		return rect.top;
	}

	void Window<"Win32">::SetTitle(const char* title)
	{
#ifdef UNICODE
		std::wstring title_str(title, title + strlen(title));
#else
		std::string title_str(title, title + strlen(title));

#endif // UNICODE
		SetWindowText(_hwnd, title_str.c_str());
	}

	void Window<"Win32">::SetSize(int width, int length)
	{
		MoveWindow
		(
			_hwnd,
			(GetSystemMetrics(SM_CXSCREEN) - width) / 2,
			(GetSystemMetrics(SM_CYSCREEN) - length) / 2,
			width,
			length,
			TRUE
		);
	}

	void Window<"Win32">::SetPosition(int x, int y)
	{
		RECT rect;
		GetWindowRect(_hwnd, &rect);
		MoveWindow
		(
			_hwnd,
			x,
			y,
			rect.right - rect.left,
			rect.bottom - rect.top,
			TRUE
		);
	}

	Graphics::Window* Window<"Win32">::Create(int width, int height, const char* title)
	{
		return new Window<"Win32">(width, height, title);
	}
}