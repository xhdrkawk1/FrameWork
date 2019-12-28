#include "stdafx.h"
#include "MainApp.h"
#include "DirectInput.h"
#include "DirectSound.h"


CMainApp::CMainApp()
{
}


CMainApp::~CMainApp()
{
	Free();
}

HRESULT CMainApp::Ready_MainApp()
{

	FAILED_CHECK_RETURN(SetUp_DefaultSetting(), E_FAIL);

	return S_OK;
}

_int CMainApp::Update_MainApp(const _float & fTimeDelta)
{
	/*____________________________________________________________________
	Direct Input
	______________________________________________________________________*/
	Engine::CDirectInput::Get_Instance()->Update_InputDev();

	return NO_EVENT;
}

_int CMainApp::LateUpdate_MainApp(const _float & fTimeDelta)
{
	
	return NO_EVENT;
}

void CMainApp::Render_Object(const _float& fTimeDelta)
{

}

HRESULT CMainApp::SetUp_DefaultSetting()
{
	/*____________________________________________________________________
	DirectInput 장치 초기화.
	______________________________________________________________________*/
	if (FAILED(Engine::CDirectInput::Get_Instance()->Ready_InputDev(g_hInst, g_hWnd, WINCX, WINCY)))
	{
		CDirectInput::Get_Instance()->Destroy_Instance();
		return E_FAIL;
	}

	/*____________________________________________________________________
	DirectSound 초기화.
	______________________________________________________________________*/
	//if (FAILED(Engine::CDirectSound::Get_Instance()->Ready_DirectSound(g_hWnd)))
	//{
	//	CDirectSound::Get_Instance()->Destroy_Instance();
	//	return E_FAIL;
	//}
	//Engine::CDirectSound::Get_Instance()->LoadDirectSoundFile(L"Logo_BGM");

	return S_OK;
}

CMainApp * CMainApp::Create()
{
	CMainApp* pInstance = new CMainApp;

	if (FAILED(pInstance->Ready_MainApp()))
	{
		delete pInstance;
		pInstance = nullptr;
	}

	return pInstance;
}

void CMainApp::Free()
{

}
