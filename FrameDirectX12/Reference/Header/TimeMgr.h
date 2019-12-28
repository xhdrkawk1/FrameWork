#pragma once
#include "Timer.h"

BEGIN(Engine)

/*____________________________________________________________________
���� ���� Timer Ŭ�������� map �����̳ʷ� ������ TimerMgr.
______________________________________________________________________*/

class ENGINE_DLL CTimerMgr
	: public CBase
{
	DECLARE_SINGLETON(CTimerMgr)

private:
	explicit CTimerMgr(void);
	virtual ~CTimerMgr(void);
	
public:
	_float	Get_TimeDelta(wstring wstrTimerTag);
	void	SetUp_TimeDelta(wstring wstrTimerTag);
public:
	HRESULT	Ready_Timer(wstring wstrTimerTag);
private:
	CTimer*	Find_Timer(wstring wstrTimerTag);

private:
	unordered_map<wstring, CTimer*>	m_mapTimer;

public:
	virtual void Free(void);
};


END