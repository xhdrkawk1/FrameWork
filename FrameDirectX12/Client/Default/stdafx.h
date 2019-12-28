﻿// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 특정 포함 파일이 들어 있는
// 포함 파일입니다.
//

#pragma once

#include "vld.h"
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 여기서 프로그램에 필요한 추가 헤더를 참조합니다.
#include <d3d12.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <functional>
#include <ctime>
#include <process.h>

using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace std;

/*____________________________________________________________________
Manager Class
______________________________________________________________________*/
#include "MathMgr.h"



/*____________________________________________________________________
Window Console창.
______________________________________________________________________*/
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 
#endif


#pragma warning(disable : 4251)