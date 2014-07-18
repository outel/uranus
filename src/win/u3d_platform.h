#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <wchar.h>

extern "C" {
#include "../u3d_context.h"
#include "../u3d_make.h"
#include "../u3d_setup.h"
}

#include "u3d_render.h"

#define MAX_LOADSTRING 100
