#pragma once
#include "Engine_Include.h"
#include "Base.h"

BEGIN(Engine)

/*____________________________________________________________________
1���� �ð� ���� �����ϴ� Timer Ŭ����.
______________________________________________________________________*/

class ENGINE_DLL CTimer :
	public CBase
{
private:
	explicit CTimer();
	virtual ~CTimer();

public:
	_float	Get_TimeDelta(void) const { return m_fTimeDelta; }
	void	SetUp_TimeDelta(void);
public:
	HRESULT	Ready_Timer(void);

private:
	LARGE_INTEGER	m_FrameTime;
	LARGE_INTEGER	m_FixTime;
	LARGE_INTEGER	m_LastTime;
	LARGE_INTEGER	m_CpuTick;

	_float			m_fTimeDelta = 0.f;

public:
	static CTimer*	Create(void);
	virtual void	Free(void);
};

END