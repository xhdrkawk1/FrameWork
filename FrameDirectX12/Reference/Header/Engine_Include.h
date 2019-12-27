#ifndef Engine_Include_h__
#define Engine_Include_h__

#include "vld.h"
// #include <Windows.h>

#include <d3d12.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

using namespace DirectX;
using namespace DirectX::PackedVector;

#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <ctime>

#include "Engine_Enum.h"
#include "Engine_Function.h"
#include "Engine_Functor.h"
#include "Engine_Macro.h"
#include "Engine_Struct.h"
#include "Engine_Typedef.h"

#pragma warning(disable : 4251)

#define DIRECTINPUT_VERSION		0x0800
#include <dinput.h>

using namespace std;

#endif // Engine_Include_h__
