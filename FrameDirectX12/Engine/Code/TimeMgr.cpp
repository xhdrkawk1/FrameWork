#include "TimeMgr.h"

USING(Engine)
IMPLEMENT_SINGLETON(CTimerMgr)

CTimerMgr::CTimerMgr(void)
{
}

CTimerMgr::~CTimerMgr(void)
{
}

_float CTimerMgr::Get_TimeDelta(wstring wstrTimerTag)
{
	/*____________________________________________________________________
	�ش� Tag���� �ش��ϴ� Timer�� TimeDelta���� ���´�.
	______________________________________________________________________*/
	CTimer* pInstance = Find_Timer(wstrTimerTag);

	if (nullptr == pInstance)
		return 0.f;


	return pInstance->Get_TimeDelta();
}

void CTimerMgr::SetUp_TimeDelta(wstring wstrTimerTag)
{
	/*____________________________________________________________________
	�ش� Tag���� �ش��ϴ� Timer ����.
	______________________________________________________________________*/
	CTimer* pInstance = Find_Timer(wstrTimerTag);
	NULL_CHECK(pInstance);

	pInstance->SetUp_TimeDelta();
}

HRESULT CTimerMgr::Ready_Timer(wstring wstrTimerTag)
{
	/*____________________________________________________________________
	Timer�� �����ϱ� ��, �ش� Tag���� map�� ����ִ��� Ž���Ѵ�.
	�̹� �����ϴ� ���̸�, ���� ������ �ʿ� �����Ƿ� �����Ѵ�.
	______________________________________________________________________*/
	CTimer* pInstance = Find_Timer(wstrTimerTag);

	if (nullptr != pInstance)
		return E_FAIL;

	/*____________________________________________________________________
	���� Tag���̸� ���� ������ ��, map�����̳ʿ� �־��ش�.
	______________________________________________________________________*/
	pInstance = CTimer::Create();
	NULL_CHECK_RETURN(pInstance, E_FAIL);

	m_mapTimer.emplace(wstrTimerTag, pInstance);


	return S_OK;
}

CTimer * CTimerMgr::Find_Timer(wstring wstrTimerTag)
{
	/*____________________________________________________________________
	�ش� Timer Tag���� Ž���Ѵ�.
	ã�� Tag���� ���ٸ� nullptr�� ��ȯ�Ѵ�.
	______________________________________________________________________*/
	auto iter_find = m_mapTimer.find(wstrTimerTag);

	if (iter_find == m_mapTimer.end())
		return nullptr;


	return iter_find->second;
}

void CTimerMgr::Free(void)
{
	for_each(m_mapTimer.begin(), m_mapTimer.end(), CDeleteMap());

	m_mapTimer.clear();
}
