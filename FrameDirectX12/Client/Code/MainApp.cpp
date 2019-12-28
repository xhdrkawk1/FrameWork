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
	_matrix temp;

	_matrix matScale;
	_matrix matRotX;
	_matrix matTrans;

	_matrix matWorld;

	matWorld = matScale * matRotX * matTrans;

	temp = CMathMgr::MatrixInverse(temp);

	_vec3 v;
	v.Normalize();

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
