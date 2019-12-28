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
	bool	Update_InputDev(); //Update 함수
	void	GetMouseLocation(int& mouseX, int& mouseY);  // 마우스 값 반환
	bool	KeyPressing(DWORD DIK);
	bool	KeyUp(DWORD DIK);		// DOWN이랑 UP은 꼭 같이 써줘야 한다
	bool	KeyDown(DWORD DIK);	// DOWN이랑 UP은 꼭 같이 써줘야 한다

	bool	KeyCombine(DWORD FirstDIK, DWORD SecondDIK);
	bool	KeyCombineUp(DWORD FirstDIK, DWORD SecondDIK);
	bool	KeyCombineDown(DWORD FirstDIK, DWORD SecondDIK);

	bool	MousePressing(MOUSEKEYSTATE estate);
	bool	MouseUp(MOUSEKEYSTATE estate);		// DOWN이랑 UP은 꼭 같이 써줘야 한다
	bool	MouseDown(MOUSEKEYSTATE estate);	// DOWN이랑 UP은 꼭 같이 써줘야 한다

	DIMOUSESTATE* GetMouseState() {
		return &m_mouseState;
	}

private:
	IDirectInput8*			m_directInput; //다이렉트 인풋 객체

	IDirectInputDevice8*	m_keyboard;	// 키보드 입력용 객체
	IDirectInputDevice8*	m_mouse;		// 마우스 입력용 객체
	IDirectInputDevice8*	m_pad;		// 마우스 입력용 객체

	UCHAR					m_VKey[MAX_VKEY];
	UCHAR					m_VCurKey;

	unsigned char			m_keyboardState[256]; // 키저장값
	unsigned char			m_KeyDown[256];
	unsigned char			m_KeyPressed[256];

	DIJOYSTATE2				m_joyState;

	DIMOUSESTATE			m_mouseState; // 마우스 값 저장용 구조체
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
