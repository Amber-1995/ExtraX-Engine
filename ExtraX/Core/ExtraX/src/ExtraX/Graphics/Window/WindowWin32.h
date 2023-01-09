#pragma once
#ifndef EXTRAX_WIN32_WINDOW_H
#define EXTRAX_WIN32_WINDOW_H

#include <ExtraX/Graphics/Window/WindowBase.h>
#include <ExtraX/Event.h>

namespace ExtraX::Graphics::Base
{
	struct Win32CallBaceEventInfo : public EventInfo<EventType::None>
	{
		HWND hWnd;
		UINT uMsg;
		WPARAM wParam;
		LPARAM lParam;
		Win32CallBaceEventInfo(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) :
			hWnd(hWnd), uMsg(uMsg), wParam(wParam), lParam(lParam)
		{
		}
		virtual ~Win32CallBaceEventInfo() = default;
	};

	template<>
	class Window<"Win32"> : public Graphics::Window
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
		Window(WNDCLASSEX wcex, Descriptor descriptor);

		Window(int width, int height, const char* title);

		virtual ~Window();

		HWND GetHandle();

		bool ShouldClose() override;

		void FrameBegin() override;

		void FrameEnd() override;

		int GetWidth() override;

		int GetHeight() override;

		int GetPositionX() override;

		int GetPositionY() override;

		void SetTitle(const char* title) override;

		void SetSize(int width, int length) override;

		void SetPosition(int x, int y) override;

		static Graphics::Window* Create(int width, int height, const char* title);

	};

}


#endif // !EXTRAX_WIN32_WINDOW_H

