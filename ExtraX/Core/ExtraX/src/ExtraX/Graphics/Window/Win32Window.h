#pragma once
#if !defined(EXTRAX_WIN32_WINDOW_H) && !defined(EXTRAX_DISABLE_WINDOWS) && defined(_WIN32)
#define EXTRAX_WIN32_WINDOW_H

#include <ExtraX/Graphics/Window/WindowBase.h>
#include <Windows.h>
#include <windowsx.h>
#include <string>


namespace ExtraX::Graphics::Base
{

	template<>
	class Window<WINDOW_LIB::Win32> : public WindowBase
	{
	public:
		struct Descriptor
		{
			DWORD     dwExStyle;
#ifdef UNICODE
			LPCWSTR    lpClassName;
			LPCWSTR    lpWindowName;
#else
			LPCSTR    lpClassName;
			LPCSTR    lpWindowName;
#endif // UNICODE
			DWORD     dwStyle;
			int       X;
			int       Y;
			int       nWidth;
			int       nHeight;
			HWND      hWndParent;
			HMENU     hMenu;
			HINSTANCE hInstance;
			LPVOID    lpParam;
		};

	private:
		bool _should_close = false;

		HWND _hwnd = nullptr;

		HINSTANCE _instance =nullptr;
#ifdef UNICODE
		std::wstring _class_name = L"ExtraX_Window_Class_Name";
#else
		std::string _class_name = "ExtraX_Window_Class_Name";
#endif // UNICODE
		
	public:
		Window(WNDCLASSEX wcex, Descriptor descriptor)
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

		Window()
		{
#ifdef UNICODE
			std::wstring title(DEFAULT_TITLE, DEFAULT_TITLE + strlen(DEFAULT_TITLE));
#else
			std::string title(DEFAULT_TITLE);
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
					Event<EVENT_TYPE::KeyDown> event_keydown((int)wParam);
					EventManager::OnEvent(event_keydown);
				}
					break;
				case WM_KEYUP:
				case WM_SYSKEYUP:
				case WM_IME_KEYUP:
					{
					Event<EVENT_TYPE::KeyUp> event_keyup((int)wParam);
					EventManager::OnEvent(event_keyup);
				}
					break;
				case WM_LBUTTONUP:
					{
					Event<EVENT_TYPE::KeyUp> event_keyup(KeyCode::LeftMouseButton);
					EventManager::OnEvent(event_keyup);
				}
					break;
				case WM_RBUTTONUP:
					{
					Event<EVENT_TYPE::KeyUp> event_keyup(KeyCode::RightMouseButton);
					EventManager::OnEvent(event_keyup);
				}
					break;
				case WM_MBUTTONUP:
					{
					Event<EVENT_TYPE::KeyUp> event_keyup(KeyCode::MiddleMouseButton);
					EventManager::OnEvent(event_keyup);
				}
					break;
				case WM_XBUTTONUP:
					switch (GET_XBUTTON_WPARAM(wParam))
					{
					case XBUTTON1:
					{
						Event<EVENT_TYPE::KeyUp> event_keyup(KeyCode::X1MouseButton);
						EventManager::OnEvent(event_keyup);
					}
					break;

					case XBUTTON2:
					{
						Event<EVENT_TYPE::KeyUp> event_keyup(KeyCode::X2MouseButton);
						EventManager::OnEvent(event_keyup);
					}
					break;
					}
					break;

				case WM_MOUSEWHEEL:
					{
					Event<EVENT_TYPE::MouseScrolled> event_mouse_scrolled(GET_WHEEL_DELTA_WPARAM(wParam) > 0 ? 1 : -1);
					EventManager::OnEvent(event_mouse_scrolled);
				}
					break;
				case WM_MOUSEMOVE:
					{
					Event<EVENT_TYPE::MouseMoved> event_mouse_moved(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
					EventManager::OnEvent(event_mouse_moved);
				}
					break;
				}

				if constexpr (DEFAULT_GUI_LIB == GUI_LIB::IMGUI)
				{
					LRESULT ImGui_ImplWin32_WndProcHandler(HWND, UINT, WPARAM, LPARAM);
					ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
				}
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
				title.c_str(),
				WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
				(GetSystemMetrics(SM_CXSCREEN) - WINDOW_WIDTH) / 2,
				(GetSystemMetrics(SM_CYSCREEN) - WINDOW_HEIGHT) / 2,
				WINDOW_WIDTH + GetSystemMetrics(SM_CXDLGFRAME) * 2,
				WINDOW_HEIGHT + GetSystemMetrics(SM_CYDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),
				NULL,
				NULL,
				GetModuleHandle(NULL),
				NULL
			);

			XX_CORE_ASSERT(_hwnd, "Failed to create Win32 window");

			ShowWindow(_hwnd, SW_SHOW);
			UpdateWindow(_hwnd);
		}

		virtual ~Window()
		{
			UnregisterClass(_class_name.c_str(), _instance);

			DestroyWindow(_hwnd);
		}

		HWND GetHandle()
		{
			return _hwnd;
		}

		bool ShouldClose() override
		{
			
			return _should_close;
		}

		void FrameBegin() override
		{
			MSG msg{};
			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT && msg.hwnd == _hwnd)
				{
					_should_close = true;
				}
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			Event<EVENT_TYPE::FrameBegin> event_frame_begin;
			EventManager::OnEvent(event_frame_begin);

		}

		void FrameEnd() override
		{
			Event<EVENT_TYPE::FrameEnd> event_frame_end;
			EventManager::OnEvent(event_frame_end);
		}

		int GetWidth() override
		{
			RECT rect;
			GetWindowRect(_hwnd, &rect);
			return rect.right - rect.left - GetSystemMetrics(SM_CXDLGFRAME) * 2;
		}

		int GetHeight() override
		{
			RECT rect;
			GetWindowRect(_hwnd, &rect);
			return rect.bottom - rect.top - GetSystemMetrics(SM_CYDLGFRAME) * 2 - GetSystemMetrics(SM_CYCAPTION);
		}

		int GetPositionX() override
		{
			RECT rect;
			GetWindowRect(_hwnd, &rect);
			return rect.left;
		}

		int GetPositionY() override
		{
			RECT rect;
			GetWindowRect(_hwnd, &rect);
			return rect.top;
		}

		void SetTitle(const char* title) override
		{
#ifdef UNICODE
			std::wstring title_str(title, title + strlen(title));
#else
			std::string title_str(title, title + strlen(title));
			
#endif // UNICODE
			SetWindowText(_hwnd, title_str.c_str());
		}

		void SetSize(int width, int length) override
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

		void SetPosition(int x, int y) override
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

	};

}


#endif // !EXTRAX_WIN32_WINDOW_H

