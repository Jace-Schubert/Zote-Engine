#pragma once

#include "Event.h"

namespace Zote
{
	class ZOTE_API WindowClose : public Event
	{
	public:
		WindowClose() {}
		EventType GetType() const override { return EventType::WindowClose; }
		static EventType GetStaticType() { return EventType::WindowClose; }
	};

	class ZOTE_API WindowResize : public Event
	{
	public:
		WindowResize(int newWidth, unsigned int newHeight) 
			: m_width(newWidth), m_height(newHeight) {}
		uint32_t GetWidth() const { return m_width; }
		uint32_t GetHeight() const { return m_height; }
		EventType GetType() const override { return EventType::WindowResize; }
		static EventType GetStaticType() { return EventType::WindowResize; }
	private:
		uint32_t m_width, m_height;
	};
}