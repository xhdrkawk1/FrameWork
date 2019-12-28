#pragma once
#include "Typedef.h"
#include <iostream>

using namespace std;


/*____________________________________________________________________
VECTOR
______________________________________________________________________*/
typedef struct tagVector2 : public XMFLOAT2
{
	explicit tagVector2()									: XMFLOAT2(0.f, 0.f)		{}
	explicit tagVector2(const _float& fX, const _float& fY) : XMFLOAT2(fX, fY)			{}
	explicit tagVector2(const _float& input)				: XMFLOAT2(input, input)	{}
	explicit tagVector2(const XMFLOAT2& input)				: XMFLOAT2(input)			{}

	/*____________________________________________________________________
	¿¬»êÀÚ ¿À¹ö·Îµù
	______________________________________________________________________*/
	// µ¡¼À
	tagVector2 operator+(const tagVector2& input)	{ return tagVector2(this->x + input.x, this->x + input.y); }

	// »¬¼À
	tagVector2 operator-(const tagVector2& input)	{ return tagVector2(this->x - input.x, this->x - input.y); }

	// °ö¼À
	tagVector2 operator*(const tagVector2& input)	{ return tagVector2(this->x * input.x, this->y * input.y); }
	tagVector2 operator*(const _int& input)			{ return tagVector2((_float)input * this->x, (_float)input * this->y); }
	tagVector2 operator*(const _float& input)		{ return tagVector2(input * this->x, input * this->y); }
	tagVector2 operator*(const _double& input)		{ return tagVector2((_float)input * this->x, (_float)input * this->y); }
	friend tagVector2 operator*(const _int& input, tagVector2& v1)		{ return tagVector2((_float)input * v1.x, (_float)input * v1.y); }
	friend tagVector2 operator*(const _float& input, tagVector2& v1)	{ return tagVector2(input * v1.x, input * v1.y); }
	friend tagVector2 operator*(const _double& input, tagVector2& v1)	{ return tagVector2((_float)input * v1.x, (_float)input * v1.y); }

	// Ãà¾à ¿¬»êÀÚ
	tagVector2 operator+=(const tagVector2& input)	{ return (*this) = (*this) + input; }
	tagVector2 operator-=(const tagVector2& input)	{ return (*this) = (*this) - input; }
	tagVector2 operator*=(const tagVector2& input)	{ return (*this) = (*this) * input; }
	tagVector2 operator*=(const _int& input)		{ return (*this) = (*this) * input; }
	tagVector2 operator*=(const _float& input)		{ return (*this) = (*this) * input; }
	tagVector2 operator*=(const _double& input)		{ return (*this) = (*this) * input; }

	// ºñ±³ ¿¬»êÀÚ
	_bool operator==(const tagVector2& input)
	{
		XMVECTOR dst = XMVectorSet(input.x, input.y, 0.f, 0.f);
		XMVECTOR src = XMVectorSet(this->x, this->y, 0.f, 0.f);
		return XMVector3Equal(dst, src);
	}

	_bool operator!=(const tagVector2& input)
	{
		XMVECTOR dst = XMVectorSet(input.x, input.y, 0.f, 0.f);
		XMVECTOR src = XMVectorSet(this->x, this->y, 0.f, 0.f);
		return !XMVector3Equal(dst, src);
	}

	/*____________________________________________________________________
	Function.
	______________________________________________________________________*/
	void Normalize()
	{
		XMVECTOR temp	= XMVectorSet(this->x, this->y, 0.f, 0.f);
		temp			= XMVector2Normalize(temp);

		this->x = XMVectorGetX(temp);
		this->y = XMVectorGetY(temp);
	}

	_float Length()
	{
		XMVECTOR temp	= XMVectorSet(this->x, this->y, 0.f, 0.f);
		temp			= XMVector2Length(temp);

		return XMVectorGetX(temp);
	}

	_float Distance(const tagVector2& vDst)
	{
		XMVECTOR dst	= XMVectorSet(vDst.x, vDst.y, 0.f, 0.f);
		XMVECTOR src	= XMVectorSet(this->x, this->y, 0.f, 0.f);
		
		XMVECTOR result	= dst - src;
		result			= XMVector2Length(result);

		return XMVectorGetX(result);
	}

	_float Dot(const tagVector2& vDst)
	{
		XMVECTOR dst	= XMVectorSet(vDst.x, vDst.y, 0.f, 0.f);
		XMVECTOR src	= XMVectorSet(this->x, this->y, 0.f, 0.f);
		XMVECTOR result	= XMVector2Dot(dst, src);
		return XMVectorGetX(result);
	}

	tagVector2 Cross_InputDst(const tagVector2& vDst)
	{
		XMVECTOR dst	= XMVectorSet(vDst.x, vDst.y, 0.f, 0.f);
		XMVECTOR src	= XMVectorSet(this->x, this->y, 0.f, 0.f);
		XMVECTOR result	= XMVector2Cross(dst, src);
		
		return tagVector2(XMVectorGetX(result), XMVectorGetY(result));
	}

	tagVector2 Cross_InputSrc(const tagVector2& vSrc)
	{
		XMVECTOR dst	= XMVectorSet(this->x, this->y, 0.f, 0.f);
		XMVECTOR src	= XMVectorSet(vSrc.x, vSrc.y, 0.f, 0.f);
		XMVECTOR result	= XMVector2Cross(dst, src);
		
		return tagVector2(XMVectorGetX(result), XMVectorGetY(result));
	}

	_float Angle(const tagVector2& vDst)
	{
		XMVECTOR v1 = XMVectorSet(this->x, this->y, 0.f, 0.f);
		XMVECTOR v2 = XMVectorSet(vDst.x, vDst.y, 0.f, 0.f);

		XMVECTOR angle		 = XMVector2AngleBetweenVectors(v1, v2);
		_float	angleRadians = XMVectorGetX(angle);

		return XMConvertToDegrees(angleRadians);
	}

	void Print() { cout << "x : " <<this->x << "\t" << "y : " <<this->y << endl; }

} _vec2;