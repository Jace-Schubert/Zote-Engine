#pragma once

#include "Event.h"

namespace Zote
{
	class ZOTE_API KeyEvent : public Event
	{
	public:
		int GetKeyCode() const { return m_keycode; }
	protected:
		KeyEvent(int keycode)
			: m_keycode(keycode) {
		}

		int m_keycode;
	};

	class ZOTE_API KeyPress : public KeyEvent
	{
	public:
		KeyPress(int keycode, int repeatCount)
			: KeyEvent(keycode), m_repeatCount(repeatCount) {
		}
		EventType GetType() const override { return EventType::KeyPress; }
		static EventType GetStaticType() { return EventType::KeyPress; }
	private:
		int m_repeatCount;
	};

	class ZOTE_API KeyRelease : public KeyEvent
	{
	public:
		KeyRelease(int keycode)
			: KeyEvent(keycode) {
		}
		EventType GetType() const override { return EventType::KeyRelease; }
		static EventType GetStaticType() { return EventType::KeyRelease; }
	};
}