#ifndef DirectInput_h__
#define DirectInput_h__


#include "Engine_Include.h"
#include "Base.h"

#define MAX_VKEY 256

BEGIN(Engine)

class ENGINE_DLL CDirectInput : public CBase
{
	DECLARE_SINGLETON(CDirectInput)

private:
	explicit CDirectInput(void);
	virtual ~CDirectInput(void);

public:
	HRESULT ReadKeyboard();
	HRESULT ReadGamePad();
	HRESULT ReadMouse();
	void ProcessInput();

public:
	HRESULT	Ready_InputDev(HINSTANCE hInst, HWND hWnd, int screenWidth, int screenHeight);
	bool	Update_InputDev(); //Update �Լ�
	void	GetMouseLocation(int& mouseX, int& mouseY);  // ���콺 �� ��ȯ
	bool	KeyPressing(DWORD DIK);
	bool	KeyUp(DWORD DIK);		// DOWN�̶� UP�� �� ���� ����� �Ѵ�
	bool	KeyDown(DWORD DIK);	// DOWN�̶� UP�� �� ���� ����� �Ѵ�

	bool	KeyCombine(DWORD FirstDIK, DWORD SecondDIK);
	bool	KeyCombineUp(DWORD FirstDIK, DWORD SecondDIK);
	bool	KeyCombineDown(DWORD FirstDIK, DWORD SecondDIK);

	bool	MousePressing(MOUSEKEYSTATE estate);
	bool	MouseUp(MOUSEKEYSTATE estate);		// DOWN�̶� UP�� �� ���� ����� �Ѵ�
	bool	MouseDown(MOUSEKEYSTATE estate);	// DOWN�̶� UP�� �� ���� ����� �Ѵ�

	DIMOUSESTATE* GetMouseState() {
		return &m_mouseState;
	}

private:
	IDirectInput8*			m_directInput; //���̷�Ʈ ��ǲ ��ü

	IDirectInputDevice8*	m_keyboard;	// Ű���� �Է¿� ��ü
	IDirectInputDevice8*	m_mouse;		// ���콺 �Է¿� ��ü
	IDirectInputDevice8*	m_pad;		// ���콺 �Է¿� ��ü

	UCHAR					m_VKey[MAX_VKEY];
	UCHAR					m_VCurKey;

	unsigned char			m_keyboardState[256]; // Ű���尪
	unsigned char			m_KeyDown[256];
	unsigned char			m_KeyPressed[256];

	DIJOYSTATE2				m_joyState;

	DIMOUSESTATE			m_mouseState; // ���콺 �� ����� ����ü
	DIMOUSESTATE			m_MousePressed;
	DIMOUSESTATE			m_MouseDown;

	UCHAR					m_Vmouse[DIM_END];
	UCHAR					m_VCurMouse;



	int m_screenWidth, m_screenHeight;
	int m_mouseX, m_mouseY;

public:
	virtual void Free(void);

};

END
#endif // DirectInput_h__
