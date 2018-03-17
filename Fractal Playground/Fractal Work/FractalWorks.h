#pragma once

#include <Windows.h>

#ifdef __cplusplus
extern "C"
{
#endif

	typedef void(*Callback)(size_t size, int* characters);

	__declspec(dllexport) void SetFinishedCallback(Callback callback);

#ifdef __cplusplus
}
#endif
