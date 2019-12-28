#include "MathMgr.h"

USING(Engine)
IMPLEMENT_SINGLETON(CMathMgr)

CMathMgr::CMathMgr()
{
}


CMathMgr::~CMathMgr()
{
	Free();
}

_matrix CMathMgr::MatrixInverse(const _matrix & input)
{
	return XMMatrixInverse(&XMMatrixDeterminant(input), input);
}

void CMathMgr::TransformCoord(_vec3 * pOut, const _vec3 * pVector, const _matrix * pMatrix)
{
	_vec4 vVector(pVector->x, pVector->y, pVector->z, 1.f);

	pOut->x = vVector.x * pMatrix->_11 
			+ vVector.y * pMatrix->_21 
			+ vVector.z * pMatrix->_31 
			+ vVector.w * pMatrix->_41;

	pOut->y = vVector.x * pMatrix->_12
			+ vVector.y * pMatrix->_22
			+ vVector.z * pMatrix->_32
			+ vVector.w * pMatrix->_42;


	pOut->z = vVector.x * pMatrix->_13
			+ vVector.y * pMatrix->_23
			+ vVector.z * pMatrix->_33
			+ vVector.w * pMatrix->_43;

	float fZ = vVector.x * pMatrix->_14
			+ vVector.y * pMatrix->_24
			+ vVector.z * pMatrix->_34
			+ vVector.w * pMatrix->_44;

	pOut->x /= fZ;
	pOut->y /= fZ;
	pOut->z /= fZ;
}

void CMathMgr::TransformNormal(_vec3 * pOut, const _vec3 * pVector, const _matrix * pMatrix)
{
	_vec4 vVector(pVector->x, pVector->y, pVector->z, 0.f);

	pOut->x = vVector.x * pMatrix->_11 
			+ vVector.y * pMatrix->_21 
			+ vVector.z * pMatrix->_31 
			+ vVector.w * pMatrix->_41;

	pOut->y = vVector.x * pMatrix->_12
			+ vVector.y * pMatrix->_22
			+ vVector.z * pMatrix->_32
			+ vVector.w * pMatrix->_42;


	pOut->z = vVector.x * pMatrix->_13
			+ vVector.y * pMatrix->_23
			+ vVector.z * pMatrix->_33
			+ vVector.w * pMatrix->_43;

	float fZ = vVector.x * pMatrix->_14
			+ vVector.y * pMatrix->_24
			+ vVector.z * pMatrix->_34
			+ vVector.w * pMatrix->_44;

	pOut->x /= fZ;
	pOut->y /= fZ;
	pOut->z /= fZ;
}

void CMathMgr::Free()
{

}
