#include "FrameMgr.h"

USING(Engine)
IMPLEMENT_SINGLETON(CFrameMgr)

CFrameMgr::CFrameMgr()
{
}


CFrameMgr::~CFrameMgr()
{
}

_bool CFrameMgr::IsPermit_Call(wstring wstrFrameTag, const _float & fTimeDelta)
{
	CFrame*	pInstance = Find_Frame(wstrFrameTag);
	NULL_CHECK_RETURN(pInstance, false);

	return pInstance->IsPermit_Call(fTimeDelta);
}

HRESULT CFrameMgr::Ready_Frame(wstring wstrFrameTag, const _float & fCallLimit)
{
	/*____________________________________________________________________
	���� �����ϱ� ����, FrameTag���� Ž���Ѵ�.
	�̹� �����ϴ� ���̸� ���� �Ҵ��� �ʿ� �����Ƿ� ����.
	______________________________________________________________________*/
	CFrame* pInstance = Find_Frame(wstrFrameTag);

	if (nullptr != pInstance)
		return E_FAIL;

	/*____________________________________________________________________
	������ ���� �Ҵ��� ��, map�����̳ʿ� �߰����ش�.
	______________________________________________________________________*/
	pInstance = CFrame::Create(fCallLimit);
	NULL_CHECK_RETURN(pInstance, E_FAIL);

	m_mapFrame.emplace(wstrFrameTag, pInstance);

	return S_OK;
}

CFrame * CFrameMgr::Find_Frame(wstring wstrFrameTag)
{
	/*____________________________________________________________________
	ã���� �ϴ� Frame Tag�� Ž���Ѵ�.
	���ٸ� nullptr ��ȯ.
	______________________________________________________________________*/
	auto iter_find = m_mapFrame.find(wstrFrameTag);

	if (iter_find == m_mapFrame.end())
		return nullptr;


	return iter_find->second;
}

void CFrameMgr::Free()
{
	for_each(m_mapFrame.begin(), m_mapFrame.end(), CDeleteMap());

	m_mapFrame.clear();
}
