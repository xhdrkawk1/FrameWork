#pragma once
#include "Typedef.h"

#include <iostream>
using namespace std;


/*____________________________________________________________________
VECTOR
______________________________________________________________________*/
typedef struct tagVector2
	: public XMFLOAT2
{
public:
	explicit tagVector2()									: XMFLOAT2(0.f, 0.f)	{}
	explicit tagVector2(const _float& fX, const _float& fY) : XMFLOAT2(fX, fY)		{}
	explicit tagVector2(const _float& fIn)					: XMFLOAT2(fIn, fIn)	{}
	explicit tagVector2(const XMFLOAT2& vIn)				: XMFLOAT2(vIn)			{}

	/*____________________________________________________________________
	¿¬»êÀÚ ¿À¹ö·Îµù
	______________________________________________________________________*/
	// µ¡¼À
	tagVector2 operator+(const tagVector2& vIn)
	{
		// (vec2 + vec2)
		return tagVector2(this->x + vIn.x, this->x + vIn.y);
	}

	// »¬¼À
	tagVector2 operator-(const tagVector2& vIn)
	{
		// (vec2 - vec2)
		return tagVector2(this->x - vIn.x, this->x - vIn.y);
	}

	// °ö¼À
	tagVector2 operator*(const tagVector2& vIn)
	{
		// vec2 * vec2
		return tagVector2(this->x * vIn.x, this->y * vIn.y);
	}

	tagVector2 operator*(const _int& input)
	{
		// vec2 * int
		return tagVector2((_float)input * this->x, (_float)input * this->y);
	}

	tagVector2 operator*(const _float& input)
	{
		// vec2 * float
		return tagVector2(input * this->x, input * this->y);
	}

	tagVector2 operator*(const _double& input)
	{
		// vec2 * double
		return tagVector2((_float)input * this->x, (_float)input * this->y);
	}

	friend tagVector2 operator*(const _int& input, tagVector2& v1)
	{
		// int * vce2
		return tagVector2((_float)input * v1.x, (_float)input * v1.y);
	}

	friend tagVector2 operator*(const _float& input, tagVector2& v1)
	{
		// float * vec2
		return tagVector2(input * v1.x, input * v1.y);
	}

	friend tagVector2 operator*(const _double& input, tagVector2& v1)
	{
		// double * vec2
		return tagVector2((_float)input * v1.x, (_float)input * v1.y);
	}

	// Ãà¾à ¿¬»êÀÚ
	tagVector2 operator+=(const tagVector2& vIn)
	{
		return (*this) = (*this) + vIn;
	}

	tagVector2 operator-=(const tagVector2& vIn)
	{
		return (*this) = (*this) - vIn;
	}

	tagVector2 operator*=(const tagVector2& vIn)
	{
		return (*this) = (*this) * vIn;
	}

	tagVector2 operator*=(const _int& input)
	{
		return (*this) = (*this) * input;
	}

	tagVector2 operator*=(const _float& input)
	{
		return (*this) = (*this) * input;
	}

	tagVector2 operator*=(const _double& input)
	{
		return (*this) = (*this) * input;
	}

	/*____________________________________________________________________
	Function.
	______________________________________________________________________*/
	void Normalize()
	{
		_vector temp	= XMVectorSet(this->x, this->y, 0.f, 0.f);
		temp			= XMVector2Normalize(temp);

		this->x = XMVectorGetX(temp);
		this->y = XMVectorGetY(temp);
	}

	_float Length()
	{
		_vector temp	= XMVectorSet(this->x, this->y, 0.f, 0.f);
		temp			= XMVector2Length(temp);

		return XMVectorGetX(temp);
	}

	_float Dot(const tagVector2& vDst)
	{
		_vector dst		= XMVectorSet(vDst.x, vDst.y, 0.f, 0.f);
		_vector src		= XMVectorSet(this->x, this->y, 0.f, 0.f);
		_vector result	= XMVector2Dot(dst, src);
		return XMVectorGetX(result);
	}

	tagVector2 CrossDst(const tagVector2& vDst)
	{
		_vector dst		= XMVectorSet(vDst.x, vDst.y, 0.f, 0.f);
		_vector src		= XMVectorSet(this->x, this->y, 0.f, 0.f);
		_vector result	= XMVector2Cross(dst, src);
		
		return tagVector2(XMVectorGetX(result), XMVectorGetY(result));
	}

	tagVector2 CrossSrc(const tagVector2& vSrc)
	{
		_vector dst		= XMVectorSet(this->x, this->y, 0.f, 0.f);
		_vector src		= XMVectorSet(vSrc.x, vSrc.y, 0.f, 0.f);
		_vector result	= XMVector2Cross(dst, src);
		
		return tagVector2(XMVectorGetX(result), XMVectorGetY(result));
	}

	_float Angle(const tagVector2& vIn)
	{
		_vector v1 = XMVectorSet(this->x, this->y, 0.f, 0.f);
		_vector v2 = XMVectorSet(vIn.x, vIn.y, 0.f, 0.f);

		_vector angle		 = XMVector2AngleBetweenVectors(v1, v2);
		_float	angleRadians = XMVectorGetX(angle);

		return XMConvertToDegrees(angleRadians);
	}

	_bool Equal(const tagVector2& vIn)
	{
		_vector dst = XMVectorSet(vIn.x, vIn.y, 0.f, 0.f);
		_vector src = XMVectorSet(this->x, this->y, 0.f, 0.f);

		return XMVector3Equal(dst, src);
	}

	void Print()
	{
		cout << "x : " <<this->x << "\t" << "y : " <<this->y << endl;
	}

} _vec2;