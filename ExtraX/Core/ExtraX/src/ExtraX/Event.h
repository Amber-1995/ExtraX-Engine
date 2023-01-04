#pragma once
#ifndef EXTRAX_EVENT_H
#define EXTRAX_EVENT_H

#include <functional>
#include <memory>

namespace ExtraX
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		FrameBegin, FrameEnd,
		KeyDown, KeyUp, KeyTyped,
		MouseMoved, MouseScrolled,
	};


	template<EventType>
	class EventInfo
	{

	};

	template<>
	class EventInfo<EventType::KeyDown>
	{
	public:
		int keycode;

		EventInfo(int keycode) :
			keycode(keycode)
		{
		}
	};

	template<>
	class EventInfo<EventType::KeyUp>
	{
	public:
		int keycode;

		EventInfo(int keycode) :
			keycode(keycode)
		{
		}
	};

	template<>
	class EventInfo<EventType::MouseMoved>
	{
	public:
		int x,y;

		EventInfo(int x, int y) :
			x(x),
			y(y)
		{
		}
	};

	template<>
	class EventInfo<EventType::MouseScrolled>
	{
	public:
		int scroll_wheel;

		EventInfo(int scroll_wheel) :
			scroll_wheel(scroll_wheel)
		{
		}
	};

	template<EventType E>
	using EventCallBack = std::shared_ptr<std::function<void(EventInfo<E>&)>>;

	template<EventType E, typename ...ARGS>
	inline EventCallBack<E> CreateEventCallBack(ARGS ...args)
	{
		return std::make_shared<std::function<void(EventInfo<E>&)>>(std::bind(args..., std::placeholders::_1));
	}

	class EventManager
	{
	private:
		template<EventType E>
		using CallBackObserve = std::weak_ptr<std::function<void(EventInfo<E>&)>>;

		template<EventType E>
		inline static std::vector<CallBackObserve<E>> _observe;

	public:
		template<EventType E>
		inline static void SetCallBack(EventCallBack<E> event_func)
		{
			_observe<E>.emplace_back(event_func);
		}

		template<EventType E>
		inline static void OnEvent(EventInfo<E>& event)
		{
			//remove expired event
			_observe<E>.erase(std::remove_if(_observe<E>.begin(), _observe<E>.end(), [](std::weak_ptr<std::function<void(EventInfo<E>&)>>& p) { return p.expired(); }), _observe<E>.end());

			for (auto& i : _observe<E>)
			{
				(*i.lock())(event);
			}
		}

	};


	
}


#endif // !EXTRAX_EVENT_H
