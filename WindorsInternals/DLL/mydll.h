#pragma once
#ifdef DLL_EXPORTS
#define MYLIBAPI extern "C" __declspec(dllexport)
#else
#define MYLIBAPI extern "C" __declspec(dllimport)
#endif
MYLIBAPI int add(int a, int b);
MYLIBAPI int sub(int a, int b);
MYLIBAPI int mul(int a, int b);
MYLIBAPI int divn(int a, int b);
