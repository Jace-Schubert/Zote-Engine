#pragma once

#include "Zote/Core.h"

namespace Zote
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize,
		KeyPress, KeyRelease,
		MouseMove, MouseButtonPress, MouseButtonRelease, MouseScroll
	};

	class ZOTE_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetType() const = 0;
		bool IsHandled() const { return m_handled; }
	protected:
		bool m_handled = false;
	};

	class ZOTE_API EventDispatcher
	{
		template <typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_event(event)
		{

		}

		template <typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_event.GetType() == T::GetStaticType())
			{
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}
	private:
		Event& m_event;
	};
}