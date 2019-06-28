#pragma once
#include <sdkddkver.h>

#ifndef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_WIN7
#endif

#ifndef WINVER
#define WINVER _WIN32_WINNT_WIN7
#endif