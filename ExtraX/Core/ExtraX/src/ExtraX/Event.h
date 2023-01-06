#pragma once
#ifndef EXTRAX_EVENT_H
#define EXTRAX_EVENT_H

#include <memory>
#include <functional>

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
	struct EventInfo
	{

	};

	template<>
	struct EventInfo<EventType::None>
	{
		virtual ~EventInfo() = default;
	};

	template<>
	struct EventInfo<EventType::KeyDown>
	{
		int keycode;

		EventInfo(int keycode) :
			keycode(keycode)
		{
		}
	};

	template<>
	struct EventInfo<EventType::KeyUp>
	{
		int keycode;

		EventInfo(int keycode) :
			keycode(keycode)
		{
		}
	};

	template<>
	struct EventInfo<EventType::MouseMoved>
	{
		int x,y;

		EventInfo(int x, int y) :
			x(x),
			y(y)
		{
		}
	};

	template<>
	struct EventInfo<EventType::MouseScrolled>
	{
		int scroll_wheel;

		EventInfo(int scroll_wheel) :
			scroll_wheel(scroll_wheel)
		{
		}
	};

	template<EventType event_type>
	using EventCallBack = std::shared_ptr<std::function<void(EventInfo<event_type>&)>>;

	template<EventType event_type, typename ...ARGS>
	inline EventCallBack<event_type> CreateEventCallBack(ARGS ...args)
	{
		return std::make_shared<std::function<void(EventInfo<event_type>&)>>(std::bind(args..., std::placeholders::_1));
	}

	class EventManager
	{
	private:
		template<EventType event_type>
		using CallBackObserve = std::weak_ptr<std::function<void(EventInfo<event_type>&)>>;

		template<EventType event_type>
		inline static std::vector<CallBackObserve<event_type>> _observe;

	public:
		template<EventType event_type>
		inline static void SetCallBack(EventCallBack<event_type> callback)
		{
			_observe<event_type>.emplace_back(callback);
		}

		template<EventType event_type>
		inline static void OnEvent(EventInfo<event_type>& event)
		{
			//remove expired event
			_observe<event_type>.erase(std::remove_if(_observe<event_type>.begin(), _observe<event_type>.end(), [](std::weak_ptr<std::function<void(EventInfo<event_type>&)>>& p) { return p.expired(); }), _observe<event_type>.end());

			for (auto& i : _observe<event_type>)
			{
				(*i.lock())(event);
			}
		}

	};


	
}


#endif // !EXTRAX_EVENT_H
