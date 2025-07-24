#pragma once

#if defined(_WIN32) || defined(_WIN64)
#ifdef SIMPLELIBDLL_EXPORTS
#define SIMPLELIBDLL_API __declspec(dllexport)  // Export when building the DLL
#else
#define SIMPLELIBDLL_API __declspec(dllimport)  // Import when using the DLL
#endif
#else
#define SIMPLELIBDLL_API __attribute__((visibility("default")))  // For Linux/macOS
#endif