#include "DirectInput.h"


LPDIRECTINPUT8          g_pDI = NULL;
LPDIRECTINPUTDEVICE8    g_pJoystick = NULL;
DIDEVCAPS				g_diDevCaps;



BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE*
	pdidInstance, VOID* pContext)
{
	HRESULT hr;

	// Obtain an interface to the enumerated joystick.
	hr = g_pDI->CreateDevice(pdidInstance->guidInstance,
		&g_pJoystick, NULL);
	if (FAILED(hr))
		return DIENUM_CONTINUE;

	return DIENUM_STOP;
}

BOOL CALLBACK EnumObjectsCallback(const DIDEVICEOBJECTINSTANCE* pdidoi,
	VOID* pContext)
{
	HWND hDlg = (HWND)pContext;

	static int nSliderCount = 0;  // Number of returned slider controls
	static int nPOVCount = 0;     // Number of returned POV controls

								  // For axes that are returned, set the DIPROP_RANGE property for the
								  // enumerated axis in order to scale min/max values.
	if (pdidoi->dwType & DIDFT_AXIS)
	{
		DIPROPRANGE diprg;
		diprg.diph.dwSize = sizeof(DIPROPRANGE);
		diprg.diph.dwHeaderSize = sizeof(DIPROPHEADER);
		diprg.diph.dwHow = DIPH_BYID;
		diprg.diph.dwObj = pdidoi->dwType; // Specify the enumerated axis
		diprg.lMin = -1000;
		diprg.lMax = +1000;

		// Set the range for the axis
		if (FAILED(g_pJoystick->SetProperty(DIPROP_RANGE, &diprg.diph)))
			return DIENUM_STOP;

	}



	return DIENUM_CONTINUE;
}


USING(Engine)
IMPLEMENT_SINGLETON(CDirectInput)

Engine::CDirectInput::CDirectInput(void)
	: m_directInput(0)
	, m_keyboard(0)
	, m_mouse(0)
{

}

Engine::CDirectInput::~CDirectInput(void)
{

}

HRESULT CDirectInput::ReadKeyboard()
{
	HRESULT result; // Read the keyboard device. 

	result = m_keyboard->GetDeviceState(sizeof(m_keyboardState), m_keyboardState);

	if (FAILED(result))
	{ 
		// If the keyboard lost focus or was not acquired then try to get control back. 
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
			m_keyboard->Acquire();
		else
			return E_FAIL;
	}
	return S_OK;
}

HRESULT CDirectInput::ReadGamePad()
{
	HRESULT     hr;
	CHAR        strText[128] = ""; // Device state text
								   // Direct Input joystick state 

	hr = g_pJoystick->Poll();
	if (FAILED(hr))
	{
		hr = g_pJoystick->Acquire();
		while (hr == DIERR_INPUTLOST)
			hr = g_pJoystick->Acquire();
		return S_OK;
	}
	if (NULL == g_pJoystick)
		return S_OK;

	// Poll the device to read the current state
	hr = g_pJoystick->Poll();
	if (FAILED(hr))
	{
		// Attempt to reacquire joystick
	}
	hr = g_pJoystick->GetDeviceState(sizeof(DIJOYSTATE2), &m_joyState);

	return S_OK;
}

HRESULT CDirectInput::ReadMouse()
{
	HRESULT result; // Read the mouse device. 
	result = m_mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouseState);
	if (FAILED(result))
	{ 
		// If the mouse lost focus or was not acquired then try to get control back. 
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
			m_mouse->Acquire();
		else
			return E_FAIL;
	}
	return S_OK;
}

void CDirectInput::ProcessInput()
{
	// Update the location of the mouse cursor based on the change of the mouse location during the frame. 
	m_mouseX += m_mouseState.lX;
	m_mouseY += m_mouseState.lY; // Ensure the mouse location doesn't exceed the screen width or height. 
	if (m_mouseX < 0)
	{
		m_mouseX = 0;
	}

	if (m_mouseY < 0)
	{
		m_mouseY = 0;
	}

	if (m_mouseX > m_screenWidth)
	{
		m_mouseX = m_screenWidth;
	}

	if (m_mouseY > m_screenHeight)
	{
		m_mouseY = m_screenHeight;
	}

	return;
}

HRESULT CDirectInput::Ready_InputDev(HINSTANCE hInst, HWND hWnd, int screenWidth, int screenHeight)
{
	// ȭ��ũ�� �Է¿� ����
	HRESULT result; // Store the screen size which will be used for positioning the mouse cursor. 
	m_screenWidth = screenWidth; m_screenHeight = screenHeight; // Initialize the location of the mouse on the screen. 

	m_mouseX = 0;
	m_mouseY = 0;

	//HRRESULT DirectInput8Create �� ��ü ������ HRESULT ����� ��ȯ
	FAILED_CHECK_RETURN(DirectInput8Create(hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_directInput, NULL), E_FAIL)

	// Initialize the direct input interface for the keyboard. 
	// Ű����� ��ü ����
	FAILED_CHECK_RETURN(m_directInput->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL), E_FAIL);

	// Set the data format. In this case since it is a keyboard we can use the predefined data format. 
	// Ű���尴ü�� Ű����Ÿ�� ������ ���� ����
	FAILED_CHECK_RETURN(m_keyboard->SetDataFormat(&c_dfDIKeyboard), E_FAIL);

	// Set the cooperative level of the keyboard to not share with other programs. 
	// �ٸ����α׷� Ȱ���ÿ��� �۵�����?
	FAILED_CHECK_RETURN(m_keyboard->SetCooperativeLevel(hWnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE), E_FAIL);

	// Now acquire the keyboard. 
	// Ű���忡 ���� ���ٱ����� ����
	FAILED_CHECK_RETURN(m_keyboard->Acquire(), E_FAIL);

	// Initialize the direct input interface for the mouse. 
	// ���콺 ��ü ����
	FAILED_CHECK_RETURN(m_directInput->CreateDevice(GUID_SysMouse, &m_mouse, NULL), E_FAIL);

	// Set the data format for the mouse using the pre-defined mouse data format. 
	//���콺 �� ������ ���� ����
	FAILED_CHECK_RETURN(m_mouse->SetDataFormat(&c_dfDIMouse), E_FAIL);

	// Set the cooperative level of the mouse to share with other programs.
	// �ٸ����α׷� Ȱ���ÿ��� �۵�����?
	FAILED_CHECK_RETURN(m_mouse->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE), E_FAIL);

	// Acquire the mouse. 
	// ���콺�� ���� ���ٱ��� ����
	HRESULT hr = m_mouse->Acquire();
	if (hr == E_FAIL)
	{
		while (1)
		{
			hr = m_mouse->Acquire();
			if(hr == S_OK)
				break;
		}
	}

	//HRRESULT DirectInput8Create �� ��ü ������ HRESULT ����� ��ȯ
	FAILED_CHECK_RETURN(DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION,
		IID_IDirectInput8, (VOID**)&g_pDI, NULL), E_FAIL);

	//��ġŬ������ ������ ���̽�ƽ�� �߰ߵ� �� �ҷ����� �Լ� EnumJoystickCallback�� �������ش� 
	g_pDI->EnumDevices(DI8DEVCLASS_GAMECTRL, EnumJoysticksCallback,
		NULL, DIEDFL_ATTACHEDONLY); // DIEDFL_ATTACHEDONLY�� ��ǻ�Ϳ�Attach�ǰ� �ִ� ��ġ�� ���� ����� �����ϴ� �÷���

	if (g_pJoystick != nullptr)
	{
		// ���̽�ƽ��ü�� c_dfDIJoystick2Ÿ�� ������ ���� ����
		if (FAILED(g_pJoystick->SetDataFormat(&c_dfDIJoystick2)))
			return E_FAIL;

		// �ٸ����α׷� Ȱ���ÿ��� �۵�����?
		if (FAILED(g_pJoystick->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE)))
			return E_FAIL;

		g_diDevCaps.dwSize = sizeof(DIDEVCAPS); //DIDEVCAPS ����ü�� ������ ���� ������ ���ȴ�
		if (FAILED(g_pJoystick->GetCapabilities(&g_diDevCaps)))
			return E_FAIL;
		//��ġ ������Ƽ�� Ŀ���͸������Ͽ� ���� ������ �缳��
		if (FAILED(g_pJoystick->EnumObjects(EnumObjectsCallback,
			(VOID*)hWnd, DIDFT_AXIS)))
			return E_FAIL;
		//��ġ�� ��� �� �������� ���
		if (FAILED(g_pJoystick->Poll()))
		{
			result = g_pJoystick->Acquire();
			while (result == DIERR_INPUTLOST)
				result = g_pJoystick->Acquire();
			return S_OK;
		}
	}

	return S_OK;
}

bool CDirectInput::Update_InputDev()
{
	// Read the current state of the keyboard. 
	// Ű���尪 �о��
	if (FAILED(ReadKeyboard()))
		return false;

	if (g_pJoystick != nullptr)
	{
		if (FAILED(ReadGamePad()))
			return false;
	}

	// Read the current state of the mouse. 
	// ���콺�� �о��
	if(FAILED(ReadMouse()))
		return false;

	// Process the changes in the mouse and keyboard. 
	// ���콺������ ���
	ProcessInput();

	return true;
}

void CDirectInput::GetMouseLocation(int& mouseX, int& mouseY)
{
	mouseX = m_mouseX;
	mouseY = m_mouseY;
}

bool CDirectInput::KeyPressing(DWORD DIK)
{
	if (m_keyboardState[DIK] & 0x80)
		return true;

	return false;
}

bool CDirectInput::KeyUp(DWORD DIK)
{
	if (m_keyboardState[DIK] & 0x80)
	{
		m_KeyPressed[DIK] = m_keyboardState[DIK];
		return false;
	}
	else if(m_KeyPressed[DIK])
	{
		m_KeyPressed[DIK] = m_keyboardState[DIK];
		return true;
	}

	return false;
}

bool CDirectInput::KeyDown(DWORD DIK)
{
	if (m_keyboardState[DIK] && !m_KeyDown[DIK])
	{
		m_KeyDown[DIK] = m_keyboardState[DIK];
		return true;
	}
	else if(!m_keyboardState[DIK] && m_KeyDown[DIK])
	{
		m_KeyDown[DIK] = m_keyboardState[DIK];
		return false;
	}

	return false;
}

bool CDirectInput::KeyCombine(DWORD FirstDIK, DWORD SecondDIK)
{
	if (m_keyboardState[FirstDIK] && KeyPressing(SecondDIK))
		return true;

	return false;
}

bool CDirectInput::KeyCombineUp(DWORD FirstDIK, DWORD SecondDIK)
{
	if (m_keyboardState[FirstDIK] && KeyUp(SecondDIK))
		return true;

	return false;
}

bool CDirectInput::KeyCombineDown(DWORD FirstDIK, DWORD SecondDIK)
{
	if (m_keyboardState[FirstDIK] && KeyDown(SecondDIK))
		return true;

	return false;
}

bool CDirectInput::MousePressing(MOUSEKEYSTATE estate)
{
	if (m_mouseState.rgbButtons[estate] & 0x80)
		return true;

	return false;
}

bool CDirectInput::MouseUp(MOUSEKEYSTATE estate)
{
	if (m_mouseState.rgbButtons[estate])
	{
		m_MousePressed.rgbButtons[estate] = m_mouseState.rgbButtons[estate];
		return false;
	}
	else if (m_MousePressed.rgbButtons[estate])
	{
		m_MousePressed.rgbButtons[estate] = m_mouseState.rgbButtons[estate];
		return true;
	}

	return false;
}

bool CDirectInput::MouseDown(MOUSEKEYSTATE estate)
{
	if (m_mouseState.rgbButtons[estate] && !m_MouseDown.rgbButtons[estate])
	{
		m_MouseDown.rgbButtons[estate] = m_mouseState.rgbButtons[estate];
		return true;
	}
	else if (!m_mouseState.rgbButtons[estate] && m_MouseDown.rgbButtons[estate])
	{
		m_MouseDown.rgbButtons[estate] = m_mouseState.rgbButtons[estate];
		return false;
	}

	return false;
}

void Engine::CDirectInput::Free(void)
{
	// Release the mouse. 
	// ���� ������ ������
	if (m_mouse)
	{
		m_mouse->Unacquire(); 
		Safe_Release(m_mouse);
	}

	// Release the pad. 
	// ���� ������ ������
	if (m_pad)
	{
		m_pad->Unacquire(); 
		Safe_Release(m_pad);
	}

	// Release the keyboard. 
	// ���� ������ ������
	if (m_keyboard)
	{
		m_keyboard->Unacquire(); 
		Safe_Release(m_keyboard);
	}

	// Release the main interface to direct input. 
	if (m_directInput)
		Safe_Release(m_directInput);
}