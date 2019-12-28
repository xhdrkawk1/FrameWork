#pragma once
#include "Engine_Include.h"

class CMathMgr
{
public:
	CMathMgr();
	~CMathMgr();

public:
	/*____________________________________________________________________
	MATRIX
	______________________________________________________________________*/
	static _matrix	MatrixInverse(const _matrix& input);

	/*____________________________________________________________________
	VECTOR
	______________________________________________________________________*/
	static void		TransformCoord(_vec3* pOut, const _vec3* pVector, const _matrix* pMatrix);
	static void		TransformNormal(_vec3* pOut, const _vec3* pVector, const _matrix* pMatrix);
};


