#pragma once

#include <Windows.h>

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct
	{
		int wow;
		const char* str;
	} Wow;

	__declspec(dllexport) void* Oh();

#ifdef __cplusplus
}
#endif