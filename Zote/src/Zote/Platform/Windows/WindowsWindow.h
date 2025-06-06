#pragma once
#include "Zote/Core.h"
#include <GLFW/glfw3.h>
#include "Zote/Window.h"

namespace Zote
{
	class ZOTE_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(const std::string& title, uint32_t width, uint32_t height);
		~WindowsWindow();

		void Shutdown();
		void OnUpdate() override;
		uint32_t GetWidth() const override;
		uint32_t GetHeight() const override;

		virtual void SetEventCallback(const EventCallbackFn& callback) override;
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

	private:
		GLFWwindow* m_window;

		struct WindowData
		{
			std::string title;
			uint32_t width, height;
			bool vSync;
			EventCallbackFn eventCallback;
		};

		WindowData m_data;
	};
};

