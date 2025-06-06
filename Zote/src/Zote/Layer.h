#pragma once
#include "Zote/Core.h"

#include "Zote/Events/Event.h"

namespace Zote
{
	class ZOTE_API Layer
	{
	public:
		virtual ~Layer();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnEvent(Event& event);
		virtual void OnUpdate();
	};
}
