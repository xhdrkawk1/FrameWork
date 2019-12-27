#include "stdafx.h"
#include "MainApp.h"


CMainApp::CMainApp()
{
}


CMainApp::~CMainApp()
{
	Free();
}

HRESULT CMainApp::Ready_MainApp()
{

	return S_OK;
}

int CMainApp::Update_MainApp(const _float & fTimeDelta)
{
	return NO_EVENT;
}

void CMainApp::LateUpdate_MainApp(const _float & fTimeDelta)
{

}

void CMainApp::Render_Object()
{

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
