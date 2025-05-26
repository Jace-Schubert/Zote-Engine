#pragma once

#ifdef ZT_PLATFORM_WINDOWS
	#ifdef ZT_BUILD_DLL
		#define ZOTE_API __declspec(dllexport)
	#else
		#define ZOTE_API __declspec(dllimport)
	#endif
#else 
	#error Zote only supports Windows!
#endif