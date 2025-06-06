#include "ztpch.h"
#include "Zote/App.h"
#include "Zote/Log.h"

namespace Zote
{
	App::App()
	{
		m_window = std::unique_ptr<Window>(Window::Create());
		m_running = true;
		m_window->SetEventCallback(std::bind(&App::OnEvent, this, std::placeholders::_1));
	}

	App::~App()
	{
	}

	void App::Run()
	{
		while (m_running)
		{
			m_window->OnUpdate();
		}
	}

	bool App::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowClose>(std::bind(&App::OnWindowClose, this, std::placeholders::_1));
		for (auto it = m_layerStack.end(); it != m_layerStack.begin();)
		{
			(*--it)->OnEvent(event);
			if (event.IsHandled())
			{
				break;
			}
		}
		return true;
	}

	bool App::OnWindowClose(WindowClose& event)
	{
		m_running = false;
		return true;
	}

	void App::PushLayer(Layer* layer)
	{
		m_layerStack.PushLayer(layer);
	}
}
