#include "ztpch.h"

#include "WindowsWindow.h"

#include "Zote/Log.h"

namespace Zote
{
	static bool s_glfwInitialized = false;

	static void GlfwErrorCallback(int errorCode, const char* message)
	{
		ZT_CORE_ERROR("GLFW Error ({0}): {1}", errorCode, message);
	}

	Window* Window::Create(const std::string& title, uint32_t width, uint32_t height)
	{
		return new WindowsWindow(title, width, height);
	}

	WindowsWindow::WindowsWindow(const std::string& title, uint32_t width, uint32_t height)
		: m_window(nullptr), m_data({ title, width, height, false })
	{
		if (!s_glfwInitialized)
		{
			int success = glfwInit();
			ZT_CORE_ASSERT(success, "GLFW initialization failed!");
			glfwSetErrorCallback(GlfwErrorCallback);
			s_glfwInitialized = true;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (!m_window)
		{
			ZT_CORE_ERROR("Window creation failed!");
		}

		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		SetVSync(true);

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPress event(key, 0);
						data.eventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyRelease event(key);
						data.eventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPress event(key, 1);
						data.eventCallback(event);
						break;
					}
				}
			});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMove event(xPos, yPos);
				data.eventCallback(event);
			});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPress event(button);
						data.eventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonRelease event(button);
						data.eventCallback(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScroll event(xOffset, yOffset);
				data.eventCallback(event);
			});

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowResize event(width, height);
				data.eventCallback(event);

				data.width = width;
				data.height = height;
			});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowClose event;
				data.eventCallback(event);
			});
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	uint32_t WindowsWindow::GetWidth() const
	{
		return m_data.width;
	}

	uint32_t WindowsWindow::GetHeight() const
	{
		return m_data.height;
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFn& callback)
	{
		m_data.eventCallback = callback;
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_data.vSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_data.vSync;
	}
}