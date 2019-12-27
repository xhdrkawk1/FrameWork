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
	int		Update_MainApp(const _float& fTimeDelta = 0);
	void	LateUpdate_MainApp(const _float& fTimeDelta = 0);
	void	Render_Object();

public:
	static CMainApp*	Create();
private:
	virtual void		Free();
};

