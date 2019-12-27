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
	_int	Update_MainApp(const _float& fTimeDelta = 0.f);
	void	LateUpdate_MainApp(const _float& fTimeDelta = 0.f);
	void	Render_Object();

public:
	static CMainApp*	Create();
private:
	virtual void		Free();
};

