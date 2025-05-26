#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Zote
{
	class ZOTE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};

}

#define ZT_CORE_TRACE(...) ::Zote::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZT_CORE_INFO(...)  ::Zote::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZT_CORE_WARN(...)  ::Zote::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZT_CORE_ERROR(...) ::Zote::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZT_CORE_FATAL(...) ::Zote::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define ZT_TRACE(...) ::Zote::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZT_INFO(...)  ::Zote::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZT_WARN(...)  ::Zote::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZT_ERROR(...) ::Zote::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZT_FATAL(...) ::Zote::Log::GetClientLogger()->fatal(__VA_ARGS__)