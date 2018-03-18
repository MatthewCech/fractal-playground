#pragma once

#include <Windows.h>
#include "Types.h"
#include "Fractal.h"

#define FWAPI __declspec(dllexport)

#ifdef __cplusplus
extern "C"
{
#endif

	FWAPI void SetBufferSize(uint width, uint height);
	FWAPI uint* GetBuffer();

	FWAPI void Start();
	FWAPI void Abort();

	FWAPI void SetFinishedCallback(Callback callback);

#ifdef __cplusplus
}
#endif
