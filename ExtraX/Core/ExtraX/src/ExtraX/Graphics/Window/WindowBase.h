#pragma once
#ifndef EXTRAX_WINDOW_BASE_H
#define EXTRAX_WINDOW_BASE_H

#include <ExtraX/Common.h>

namespace ExtraX::Graphics::Base
{
	inline constexpr int WINDOW_WIDTH = 800;

	inline constexpr int WINDOW_HEIGHT = 600;

	inline constexpr int TITLE_MAX = 128;

	inline const char* DEFAULT_TITLE = "ExtraX";

	class WindowBase
	{
	public:
		virtual bool ShouldClose() = 0;
		virtual void FrameBegin() = 0;
		virtual void FrameEnd() = 0;
		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;
		virtual int GetPositionX() = 0;
		virtual int GetPositionY() = 0;
		virtual void SetTitle(const char* title) = 0;
		virtual void SetSize(int width, int height) = 0;
		virtual void SetPosition(int x, int y) = 0;
	};

	template<WINDOW_LIB>
	class Window;
}



#endif // !EXTRAX_SIMPLE_WINDOW_BASE_H
