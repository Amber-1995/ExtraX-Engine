#pragma once
#ifndef EXTRAX_EVENT_MANAGER_H
#define EXTRAX_EVENT_MANAGER_H

#include <ExtraX/Events/Event.h>
#include <functional>
#include <memory>

namespace ExtraX
{

	template<EVENT_TYPE EventType>
	using EventFuncion = std::shared_ptr<std::function<void(Event<EventType>&)>>;

	template<EVENT_TYPE EventType,typename ...ARGS>
	inline EventFuncion<EventType> MakeEventFuncion(ARGS ...args)
	{
		return std::make_shared<std::function<void(Event<EventType>&)>>(std::bind(args..., std::placeholders::_1));
	}

	class EventManager
	{
	private:
		template<EVENT_TYPE EventType>
		using EventObserve = std::weak_ptr<std::function<void(Event<EventType>&)>>;

		template<EVENT_TYPE EventType>
		inline static std::vector<EventObserve<EventType>> _observe;

	public:
		template<EVENT_TYPE EventType>
		inline static void BindEvent(EventFuncion<EventType> event_func)
		{
			_observe<EventType>.emplace_back(event_func);
		}

		template<EVENT_TYPE EventType>
		inline static void OnEvent(Event<EventType>& event)
		{
			//remove expired event
			_observe<EventType>.erase(std::remove_if(_observe<EventType>.begin(), _observe<EventType>.end(), [](std::weak_ptr<std::function<void(Event<EventType>&)>>& p) { return p.expired(); }), _observe<EventType>.end());

			for (auto& i : _observe<EventType>)
			{
				(*i.lock())(event);
			}
		}

	};
}


#endif // !EXTRAX_EVENT_MANAGER_H

