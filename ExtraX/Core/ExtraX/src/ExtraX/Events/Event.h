#pragma once
#ifndef EXTRAX_EVENT_H
#define EXTRAX_EVENT_H


namespace ExtraX
{
	enum class EVENT_TYPE
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		FrameBegin, FrameEnd,
		KeyDown, KeyUp, KeyTyped,
		MouseMoved, MouseScrolled,
	};


	template<EVENT_TYPE>
	class Event
	{

	};

	template<>
	class Event<EVENT_TYPE::KeyDown>
	{
	public:
		int keycode;

		Event(int keycode) :
			keycode(keycode)
		{
		}
	};

	template<>
	class Event<EVENT_TYPE::KeyUp>
	{
	public:
		int keycode;

		Event(int keycode) :
			keycode(keycode)
		{
		}
	};

	template<>
	class Event<EVENT_TYPE::MouseMoved>
	{
	public:
		int x,y;

		Event(int x, int y) :
			x(x),
			y(y)
		{
		}
	};

	template<>
	class Event<EVENT_TYPE::MouseScrolled>
	{
	public:
		int scroll_wheel;

		Event(int scroll_wheel) :
			scroll_wheel(scroll_wheel)
		{
		}
	};


	
}


#endif // !EXTRAX_EVENT_H
