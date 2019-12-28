#pragma once
#include "Typedef.h"
#include <iostream>

using namespace std;

/*____________________________________________________________________
VECTOR2
______________________________________________________________________*/
typedef struct tagVector2 : public XMFLOAT2
{
	explicit tagVector2()									: XMFLOAT2(0.f, 0.f)		{}
	explicit tagVector2(const _float& x, const _float& y)	: XMFLOAT2(x, y)			{}
	explicit tagVector2(const _float& input)				: XMFLOAT2(input, input)	{}
	explicit tagVector2(const XMFLOAT2& input)				: XMFLOAT2(input)			{}

	/*____________________________________________________________________
	¿¬»êÀÚ ¿À¹ö·Îµù
	______________________________________________________________________*/
	// µ¡¼À
	tagVector2 operator+(const tagVector2& input)	{ return tagVector2(this->x + input.x, this->y + input.y); }

	// »¬¼À
	tagVector2 operator-(const tagVector2& input)	{ return tagVector2(this->x - input.x, this->y - input.y); }

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
		return XMVector2Equal(dst, src);
	}

	_bool operator!=(const tagVector2& input)
	{
		XMVECTOR dst = XMVectorSet(input.x, input.y, 0.f, 0.f);
		XMVECTOR src = XMVectorSet(this->x, this->y, 0.f, 0.f);
		return !XMVector2Equal(dst, src);
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
		XMVECTOR v1 = XMVectorSet(vDst.x, vDst.y, 0.f, 0.f);
		XMVECTOR v2 = XMVectorSet(this->x, this->y, 0.f, 0.f);

		XMVECTOR angle		 = XMVector2AngleBetweenVectors(v1, v2);
		_float	angleRadians = XMVectorGetX(angle);

		return XMConvertToDegrees(angleRadians);
	}

	void Print() { cout << "x : " << this->x << "\t y : " << this->y << endl; }

}_vec2;

/*____________________________________________________________________
VECTOR3
______________________________________________________________________*/
typedef struct tagVector3 : public XMFLOAT3
{
	explicit tagVector3()													: XMFLOAT3(0.f, 0.f, 0.f)		{}
	explicit tagVector3(const _float& x, const _float& y, const _float& z)	: XMFLOAT3(x, y, z)				{}
	explicit tagVector3(const _float& input)								: XMFLOAT3(input, input, input)	{}
	explicit tagVector3(const XMFLOAT3& input)								: XMFLOAT3(input)				{}

	/*____________________________________________________________________
	¿¬»êÀÚ ¿À¹ö·Îµù
	______________________________________________________________________*/
	// µ¡¼À
	tagVector3 operator+(const tagVector3& input)	{ return tagVector3(this->x + input.x, this->y + input.y, this->z + input.z); }

	// »¬¼À
	tagVector3 operator-(const tagVector3& input)	{ return tagVector3(this->x - input.x, this->y - input.y, this->z - input.z); }

	// °ö¼À
	tagVector3 operator*(const tagVector3& input)	{ return tagVector3(this->x * input.x, this->y * input.y, this->z * input.z); }
	tagVector3 operator*(const _int& input)			{ return tagVector3((_float)input * this->x, (_float)input * this->y, (_float)input * this->z); }
	tagVector3 operator*(const _float& input)		{ return tagVector3(input * this->x, input * this->y, input * this->z); }
	tagVector3 operator*(const _double& input)		{ return tagVector3((_float)input * this->x, (_float)input * this->y, (_float)input * this->z); }
	friend tagVector3 operator*(const _int& input, tagVector3& v1)		{ return tagVector3((_float)input * v1.x, (_float)input * v1.y, (_float)input * v1.z); }
	friend tagVector3 operator*(const _float& input, tagVector3& v1)	{ return tagVector3(input * v1.x, input * v1.y, input * v1.z); }
	friend tagVector3 operator*(const _double& input, tagVector3& v1)	{ return tagVector3((_float)input * v1.x, (_float)input * v1.y, (_float)input * v1.z); }

	// Ãà¾à ¿¬»êÀÚ
	tagVector3 operator+=(const tagVector3& input)	{ return (*this) = (*this) + input; }
	tagVector3 operator-=(const tagVector3& input)	{ return (*this) = (*this) - input; }
	tagVector3 operator*=(const tagVector3& input)	{ return (*this) = (*this) * input; }
	tagVector3 operator*=(const _int& input)		{ return (*this) = (*this) * input; }
	tagVector3 operator*=(const _float& input)		{ return (*this) = (*this) * input; }
	tagVector3 operator*=(const _double& input)		{ return (*this) = (*this) * input; }

	// ºñ±³ ¿¬»êÀÚ
	_bool operator==(const tagVector3& input)
	{
		XMVECTOR dst = XMVectorSet(input.x, input.y, input.z, 0.f);
		XMVECTOR src = XMVectorSet(this->x, this->y, this->z, 0.f);
		return XMVector3Equal(dst, src);
	}

	_bool operator!=(const tagVector3& input)
	{
		XMVECTOR dst = XMVectorSet(input.x, input.y, input.z, 0.f);
		XMVECTOR src = XMVectorSet(this->x, this->y, this->z, 0.f);
		return !XMVector3Equal(dst, src);
	}

	/*____________________________________________________________________
	Function.
	______________________________________________________________________*/
	void Normalize()
	{
		XMVECTOR temp	= XMVectorSet(this->x, this->y, this->z, 0.f);
		temp			= XMVector3Normalize(temp);

		this->x = XMVectorGetX(temp);
		this->y = XMVectorGetY(temp);
		this->z = XMVectorGetZ(temp);
	}

	_float Length()
	{
		XMVECTOR temp	= XMVectorSet(this->x, this->y, this->z, 0.f);
		temp			= XMVector3Length(temp);

		return XMVectorGetX(temp);
	}

	_float Distance(const tagVector3& vDst)
	{
		XMVECTOR dst	= XMVectorSet(vDst.x, vDst.y, vDst.z, 0.f);
		XMVECTOR src	= XMVectorSet(this->x, this->y, this->z, 0.f);
		
		XMVECTOR result	= dst - src;
		result			= XMVector3Length(result);

		return XMVectorGetX(result);
	}

	_float Dot(const tagVector3& vDst)
	{
		XMVECTOR dst	= XMVectorSet(vDst.x, vDst.y, vDst.z, 0.f);
		XMVECTOR src	= XMVectorSet(this->x, this->y, this->z, 0.f);
		XMVECTOR result	= XMVector3Dot(dst, src);
		return XMVectorGetX(result);
	}

	tagVector3 Cross_InputDst(const tagVector3& vDst)
	{
		XMVECTOR dst	= XMVectorSet(vDst.x, vDst.y, vDst.z, 0.f);
		XMVECTOR src	= XMVectorSet(this->x, this->y, this->z, 0.f);
		XMVECTOR result	= XMVector3Cross(dst, src);
		
		return tagVector3(XMVectorGetX(result), XMVectorGetY(result), XMVectorGetZ(result));
	}

	tagVector3 Cross_InputSrc(const tagVector3& vSrc)
	{
		XMVECTOR dst	= XMVectorSet(this->x, this->y, this->z, 0.f);
		XMVECTOR src	= XMVectorSet(vSrc.x, vSrc.y, vSrc.z, 0.f);
		XMVECTOR result	= XMVector3Cross(dst, src);
		
		return tagVector3(XMVectorGetX(result), XMVectorGetY(result), XMVectorGetZ(result));
	}

	_float Angle(const tagVector3& vDst)
	{
		XMVECTOR v1 = XMVectorSet(vDst.x, vDst.y, vDst.z, 0.f);
		XMVECTOR v2 = XMVectorSet(this->x, this->y, this->z, 0.f);

		XMVECTOR angle		 = XMVector3AngleBetweenVectors(v1, v2);
		_float	angleRadians = XMVectorGetX(angle);

		return XMConvertToDegrees(angleRadians);
	}

	void Print() { cout << "x : " << this->x << "\t y : " << this->y << "\t z : " << this->z << endl; }

}_vec3;

/*____________________________________________________________________
VECTOR4
______________________________________________________________________*/
typedef struct tagVector4 : public XMFLOAT4
{
	explicit tagVector4()																	: XMFLOAT4(0.f, 0.f, 0.f, 0.f)			{}
	explicit tagVector4(const _float& x, const _float& y, const _float& z, const _float& w)	: XMFLOAT4(x, y, z, w)					{}
	explicit tagVector4(const _float& input)												: XMFLOAT4(input, input, input, input)	{}
	explicit tagVector4(const XMFLOAT4& input)												: XMFLOAT4(input)						{}

	/*____________________________________________________________________
	¿¬»êÀÚ ¿À¹ö·Îµù
	______________________________________________________________________*/
	// µ¡¼À
	tagVector4 operator+(const tagVector4& input)	{ return tagVector4(this->x + input.x, this->y + input.y, this->z + input.z, this->w + input.w); }

	// »¬¼À
	tagVector4 operator-(const tagVector4& input)	{ return tagVector4(this->x - input.x, this->y - input.y, this->z - input.z, this->w - input.w); }

	// °ö¼À
	tagVector4 operator*(const tagVector4& input)	{ return tagVector4(this->x * input.x, this->y * input.y, this->z * input.z, this->w * input.w); }
	tagVector4 operator*(const _int& input)			{ return tagVector4((_float)input * this->x, (_float)input * this->y, (_float)input * this->z, (_float)input * this->w); }
	tagVector4 operator*(const _float& input)		{ return tagVector4(input * this->x, input * this->y, input * this->z, input * this->w); }
	tagVector4 operator*(const _double& input)		{ return tagVector4((_float)input * this->x, (_float)input * this->y, (_float)input * this->z, (_float)input * this->w); }
	friend tagVector4 operator*(const _int& input, tagVector4& v1)		{ return tagVector4((_float)input * v1.x, (_float)input * v1.y, (_float)input * v1.z, (_float)input * v1.w); }
	friend tagVector4 operator*(const _float& input, tagVector4& v1)	{ return tagVector4(input * v1.x, input * v1.y, input * v1.z, input * v1.w); }
	friend tagVector4 operator*(const _double& input, tagVector4& v1)	{ return tagVector4((_float)input * v1.x, (_float)input * v1.y, (_float)input * v1.z, (_float)input * v1.w); }

	// Ãà¾à ¿¬»êÀÚ
	tagVector4 operator+=(const tagVector4& input)	{ return (*this) = (*this) + input; }
	tagVector4 operator-=(const tagVector4& input)	{ return (*this) = (*this) - input; }
	tagVector4 operator*=(const tagVector4& input)	{ return (*this) = (*this) * input; }
	tagVector4 operator*=(const _int& input)		{ return (*this) = (*this) * input; }
	tagVector4 operator*=(const _float& input)		{ return (*this) = (*this) * input; }
	tagVector4 operator*=(const _double& input)		{ return (*this) = (*this) * input; }

	// ºñ±³ ¿¬»êÀÚ
	_bool operator==(const tagVector4& input)
	{
		XMVECTOR dst = XMVectorSet(input.x, input.y, input.z, input.w);
		XMVECTOR src = XMVectorSet(this->x, this->y, this->z, this->w);
		return XMVector4Equal(dst, src);
	}

	_bool operator!=(const tagVector4& input)
	{
		XMVECTOR dst = XMVectorSet(input.x, input.y, input.z, input.w);
		XMVECTOR src = XMVectorSet(this->x, this->y, this->z, this->w);
		return !XMVector4Equal(dst, src);
	}

	/*____________________________________________________________________
	Function.
	______________________________________________________________________*/
	void Normalize()
	{
		XMVECTOR temp	= XMVectorSet(this->x, this->y, this->z, this->w);
		temp			= XMVector4Normalize(temp);

		this->x = XMVectorGetX(temp);
		this->y = XMVectorGetY(temp);
		this->z = XMVectorGetZ(temp);
		this->w = XMVectorGetW(temp);
	}

	_float Length()
	{
		XMVECTOR temp	= XMVectorSet(this->x, this->y, this->z, this->w);
		temp			= XMVector4Length(temp);

		return XMVectorGetX(temp);
	}

	_float Distance(const tagVector4& vDst)
	{
		XMVECTOR dst	= XMVectorSet(vDst.x, vDst.y, vDst.z, vDst.w);
		XMVECTOR src	= XMVectorSet(this->x, this->y, this->z, this->w);
		
		XMVECTOR result	= dst - src;
		result			= XMVector4Length(result);

		return XMVectorGetX(result);
	}

	_float Dot(const tagVector4& vDst)
	{
		XMVECTOR dst	= XMVectorSet(vDst.x, vDst.y, vDst.z, vDst.w);
		XMVECTOR src	= XMVectorSet(this->x, this->y, this->z, this->w);
		XMVECTOR result	= XMVector4Dot(dst, src);
		return XMVectorGetX(result);
	}

	tagVector4 Cross_Input_V1_V2(const tagVector4& v1, const tagVector4& v2)
	{
		XMVECTOR V1		= XMVectorSet(v1.x, v1.y, v1.z, v1.w);
		XMVECTOR V2		= XMVectorSet(v2.x, v2.y, v2.z, v2.w);
		XMVECTOR V3		= XMVectorSet(this->x, this->y, this->z, this->w);
		XMVECTOR result	= XMVector4Cross(V1, V2, V3);
		
		return tagVector4(XMVectorGetX(result), XMVectorGetY(result), XMVectorGetZ(result), XMVectorGetW(result));
	}

	tagVector4 Cross_Input_V2_V3(const tagVector4& v2, const tagVector4& v3)
	{
		XMVECTOR V1		= XMVectorSet(this->x, this->y, this->z, this->w);
		XMVECTOR V2		= XMVectorSet(v2.x, v2.y, v2.z, v2.w);
		XMVECTOR V3		= XMVectorSet(v3.x, v3.y, v3.z, v3.w);
		XMVECTOR result	= XMVector4Cross(V1, V2, V3);
		
		return tagVector4(XMVectorGetX(result), XMVectorGetY(result), XMVectorGetZ(result), XMVectorGetW(result));
	}

	tagVector4 Cross_Input_V1_V3(const tagVector4& v1, const tagVector4& v3)
	{
		XMVECTOR V1		= XMVectorSet(v1.x, v1.y, v1.z, v1.w);
		XMVECTOR V2		= XMVectorSet(this->x, this->y, this->z, this->w);
		XMVECTOR V3		= XMVectorSet(v3.x, v3.y, v3.z, v3.w);
		XMVECTOR result	= XMVector4Cross(V1, V2, V3);
		
		return tagVector4(XMVectorGetX(result), XMVectorGetY(result), XMVectorGetZ(result), XMVectorGetW(result));
	}

	_float Angle(const tagVector4& vDst)
	{
		XMVECTOR v1 = XMVectorSet(this->x, this->y, this->z, this->w);
		XMVECTOR v2 = XMVectorSet(vDst.x, vDst.y, vDst.z, vDst.w);

		XMVECTOR angle		 = XMVector4AngleBetweenVectors(v1, v2);
		_float	angleRadians = XMVectorGetX(angle);

		return XMConvertToDegrees(angleRadians);
	}

	void Print() { cout << "x : " << this->x << "\t y : " << this->y << "\t z : " << this->z << "\t w : " << this->w << endl; }

}_vec4;