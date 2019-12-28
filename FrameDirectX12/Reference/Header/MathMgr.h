#pragma once
#include "Engine_Include.h"
#include "Base.h"

BEGIN(Engine)

class ENGINE_DLL CMathMgr : public CBase
{
	DECLARE_SINGLETON(CMathMgr)

private:
	explicit CMathMgr();
	virtual ~CMathMgr();

public:
	/*____________________________________________________________________
	MATRIX
	______________________________________________________________________*/
	_matrix	MatrixInverse(const _matrix& input);

	/*____________________________________________________________________
	VECTOR
	______________________________________________________________________*/
	void	TransformCoord(_vec3* pOut, const _vec3* pVector, const _matrix* pMatrix);
	void	TransformNormal(_vec3* pOut, const _vec3* pVector, const _matrix* pMatrix);

private:
	virtual void Free();
};

END
