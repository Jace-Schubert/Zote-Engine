#pragma once
#include "ztpch.h"

#include "Zote/Core.h"
#include "Zote/Events/KeyEvent.h"
#include "Zote/Events/MouseEvent.h"
#include "Zote/Events/WindowEvent.h"

namespace Zote
{
	using EventCallbackFn = std::function<bool(Event& event)>;
	class ZOTE_API Window
	{
	public:
		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const std::string& title = "Zote Engine", uint32_t width = 1280, uint32_t height = 720);
	};
}