#pragma once

#include "glm/glm.hpp"
#include "Event.h"

namespace Zote
{
	class ZOTE_API MouseMove : public Event
	{
	public:
		MouseMove(float xPos, float yPos)
			: m_pos({ xPos, yPos }) {}
		glm::vec2 GetPos() const { return m_pos; }
		EventType GetType() const override { return EventType::MouseMove; }
		static EventType GetStaticType() { return EventType::MouseMove; }
	private:
		glm::vec2 m_pos;
	};

	class ZOTE_API MouseButtonEvent : public Event
	{
	public:
		int GetButton() const { return m_button; }
	protected:
		MouseButtonEvent(int button)
			: m_button(button) {}

		int m_button;
	};

	class ZOTE_API MouseButtonPress : public MouseButtonEvent
	{
	public:
		MouseButtonPress(int button)
			: MouseButtonEvent(button) {}
		EventType GetType() const override { return EventType::MouseButtonPress; }
		static EventType GetStaticType() { return EventType::MouseButtonPress; }
	};

	class ZOTE_API MouseButtonRelease : public MouseButtonEvent
	{
	public:
		MouseButtonRelease(int button)
			: MouseButtonEvent(button) {}
		EventType GetType() const override { return EventType::MouseButtonRelease; }
		static EventType GetStaticType() { return EventType::MouseButtonRelease; }
	};

	class ZOTE_API MouseScroll : public Event
	{
	public:
		MouseScroll(float xOffset, float yOffset)
			: m_offset({ xOffset, yOffset }) {}
		glm::vec2 GetOffset() const { return m_offset; }
		EventType GetType() const override { return EventType::MouseScroll; }
		static EventType GetStaticType() { return EventType::MouseScroll; }
	private:
		glm::vec2 m_offset;
	};
}

