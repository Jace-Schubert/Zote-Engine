#pragma once

using uint32_t = unsigned int;

#ifdef ZT_PLATFORM_WINDOWS
	#ifdef ZT_BUILD_DLL
		#define ZOTE_API __declspec(dllexport)
	#else
		#define ZOTE_API __declspec(dllimport)
	#endif
#else 
	#error Zote only supports Windows!
#endif

#ifdef ZT_ENABLE_ASSERTS
	#define ZT_ASSERT(x, ...) { if(!(x)) { ZT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ZT_CORE_ASSERT(x, ...) { if(!(x)) { ZT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ZT_ASSERT(x, ...)
	#define ZT_CORE_ASSERT(x, ...)
#endif