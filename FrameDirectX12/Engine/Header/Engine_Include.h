#ifndef Engine_Include_h__
#define Engine_Include_h__

#include "vld.h"
// #include <Windows.h>

#include <d3d12.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <functional>
#include <ctime>
#include <iostream>
#include <fstream>
#include <io.h>
#include <tchar.h>

#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

#include "Engine_Enum.h"
#include "Engine_Function.h"
#include "Engine_Functor.h"
#include "Engine_Macro.h"
#include "Engine_Typedef.h"
#include "Engine_Struct.h"

#pragma warning(disable : 4251)

/*____________________________________________________________________
DirectInput
______________________________________________________________________*/
#define DIRECTINPUT_VERSION		0x0800
#include <dinput.h>

/*____________________________________________________________________
DirectSound
______________________________________________________________________*/
#include <mmsystem.h>
#include <dsound.h>
#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")

using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace std;

#endif // Engine_Include_h__
