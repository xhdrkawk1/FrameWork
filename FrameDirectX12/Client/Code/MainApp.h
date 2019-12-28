#pragma once
#include "Include.h"
#include "Base.h"

class CMainApp
	: public CBase
{
private:
	explicit CMainApp();
	virtual ~CMainApp();

public:
	HRESULT Ready_MainApp();
	_int	Update_MainApp(const _float& fTimeDelta);
	_int	LateUpdate_MainApp(const _float& fTimeDelta);
	void	Render_Object(const _float& fTimeDelta);
private:
	HRESULT	SetUp_DefaultSetting();

public:
	static CMainApp*	Create();
private:
	virtual void		Free();
};

