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
	// _vec2 Test
	_vec2 v1(1.f, 2.f);
	_vec2 v2(5.f, 3.f);
	_vec2 result;
	
	cout << "v1 \t";
	v1.Print();
	cout << "v2 \t";
	v2.Print();
	

	cout << "[ Add ]" << endl;
	result += v1;
	result += v2;
	result.Print();

	result = v1 + v2;
	result.Print();

	result = v1 * 2.f;
	result.Print();

	cout << "[ Multiple ]" << endl;
	result = v1 * v2;
	result.Print();

	result = v1 * 2;
	result.Print();
		
	result = v1 * 2.f;
	result.Print();

	result = v1 * 2.;
	result.Print();

	result = 2.f * v1;
	result.Print();

	result = 2 * v1;
	result.Print();

	result = 2. * v1;
	result.Print();

	cout << "[ equal ]" << endl;
	cout << (v1 == v2) << endl;
	cout << (v1 != v2) << endl;
	cout << endl;

	cout << "[ length ]" << endl;
	cout << v1.Length() << endl;
	cout << v2.Length() << endl;
	cout << endl;

	cout << "[ dot ]" << endl;
	cout << v1.Dot(v2) << endl;
	cout << v2.Dot(v1) << endl;
	cout << endl;

	cout << "[ cross ]" << endl;
	v1.Cross_InputDst(v2).Print();
	v1.Cross_InputSrc(v2).Print();
	cout << endl;

	cout << "[ angle ]" << endl;
	cout << v1.Angle(v2) << endl;
	cout << endl;

	cout << "[ distance ]" << endl;
	cout << v1.Distance(v2) << endl;
	cout << v2.Distance(v1) << endl;
	cout << endl;

	cout << "[ normalize ]" << endl;
	v1.Normalize();
	v1.Print();

	v2.Normalize();
	v2.Print();






	system("pause");

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
