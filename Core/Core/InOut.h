#pragma once

#ifdef _DIARY_CORE_OUT
#define _DIARY_CORE_API __declspec(dllexport)
#else
#define _DIARY_CORE_API __declspec(dllimport)
#endif // _DIARY_CORE_OUT

typedef signed char byte;