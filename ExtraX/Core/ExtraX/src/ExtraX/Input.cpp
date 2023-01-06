#include <XXPch.h>
#include <ExtraX/Event.h>
#include "Input.h"

namespace ExtraX
{
	std::bitset<0xff> Input::_key_states_current;

	std::bitset<0xff> Input::_key_states_latest;

	int Input::_scroll_wheel;

	int Input::_mouse_position_x;

	int Input::_mouse_position_y;

	EventCallBack<EventType::KeyDown> Input::_event_key_down;

	EventCallBack<EventType::KeyUp> Input::_event_key_up;

	EventCallBack<EventType::MouseMoved> Input::_event_mouse_moved;

	EventCallBack<EventType::MouseScrolled> Input::_event_mouse_scrolled;

	EventCallBack<EventType::FrameEnd> Input::_event_frame_end;

	void Input::Init()
	{
		_event_key_down = CreateEventCallBack<EventType::KeyDown>(Input::OnKeyDown);
		EventManager::SetCallBack(_event_key_down);
		_event_key_up = CreateEventCallBack<EventType::KeyUp>(Input::OnKeyUp);
		EventManager::SetCallBack(_event_key_up);
		_event_mouse_moved = CreateEventCallBack<EventType::MouseMoved>(Input::OnMouseMoved);
		EventManager::SetCallBack(_event_mouse_moved);
		_event_mouse_scrolled = CreateEventCallBack<EventType::MouseScrolled>(Input::OnMouseScrolled);
		EventManager::SetCallBack(_event_mouse_scrolled);
		_event_frame_end = CreateEventCallBack<EventType::FrameEnd>(Input::OnFrameEnd);
		EventManager::SetCallBack(_event_frame_end);
	}

	bool Input::GetKey(size_t keycode)
	{
		return _key_states_current[keycode];
	}

	bool Input::GetKeyDown(size_t keycode)
	{
		return ((!_key_states_latest[keycode]) && _key_states_current[keycode]);
	}

	bool Input::GetKeyUp(size_t keycode)
	{
		return (_key_states_latest[keycode] && (!_key_states_current[keycode]));
	}

	int Input::GetScroolWheel()
	{
		return _scroll_wheel;
	}

	int Input::GetMousePositionX()
	{
		return _mouse_position_x;
	}

	int Input::GetMousePositionY()
	{
		return _mouse_position_y;
	}

	void Input::Reset()
	{
		_key_states_current.reset();
		_key_states_latest.reset();
	}

	void Input::OnKeyDown(EventInfo<EventType::KeyDown>& event)
	{
		_key_states_current[event.keycode] = true;
	}

	void Input::OnKeyUp(EventInfo<EventType::KeyUp>& event)
	{
		_key_states_current[event.keycode] = false;
	}

	void Input::OnMouseScrolled(EventInfo<EventType::MouseScrolled>& event)
	{
		_scroll_wheel += event.scroll_wheel;
	}

	void Input::OnMouseMoved(EventInfo<EventType::MouseMoved>& event)
	{
		_mouse_position_x = event.x;
		_mouse_position_y = event.y;
	}

	void Input::OnFrameEnd(EventInfo<EventType::FrameEnd>& event)
	{
		_key_states_latest = _key_states_current;
		_scroll_wheel = 0;
	}
}