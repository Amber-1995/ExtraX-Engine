#pragma once
#ifndef EXTRAX_EVENT_H
#define EXTRAX_EVENT_H


namespace ExtraX
{
	enum class EVEVT_TYPE
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		FrameBegin, FrameEnd,
		KeyDown, KeyUp, KeyTyped,
		MouseMoved, MouseScrolled,
	};


	template<EVEVT_TYPE>
	class Event
	{

	};


	
}


#endif // !EXTRAX_EVENT_H
