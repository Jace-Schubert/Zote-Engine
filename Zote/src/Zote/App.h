#pragma once

#include "Zote/Core.h"
#include "Zote/Window.h"
#include "Zote/Events/WindowEvent.h"
#include "Zote/LayerStack.h"

namespace Zote
{
	class ZOTE_API App
	{
	public:
		App();
		virtual ~App();

		void Run();

		bool OnEvent(Event& event);

		bool OnWindowClose(WindowClose& event);

		void PushLayer(Layer* layer);
	private:
		std::unique_ptr<Window> m_window;
		LayerStack m_layerStack;
		bool m_running;
	};

	App* CreateApp();
}

