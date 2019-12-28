#ifndef Engine_Struct_h__
#define Engine_Struct_h__

#include <DirectXMath.h>

USING(std)
USING(Engine)
USING(DirectX)

/*____________________________________________________________________
VECTOR2
______________________________________________________________________*/
typedef struct tagVector2 : public XMFLOAT2
{
	explicit tagVector2() : XMFLOAT2(0.f, 0.f) {}
	explicit tagVector2(const float& x, const float& y) : XMFLOAT2(x, y) {}
	explicit tagVector2(const float& input) : XMFLOAT2(input, input) {}
	explicit tagVector2(const XMFLOAT2& input) : XMFLOAT2(input) {}

	/*____________________________________________________________________
	������ �����ε�
	______________________________________________________________________*/
	// ����
	tagVector2 operator+(const tagVector2& input) { return tagVector2(this->x + input.x, this->y + input.y); }

	// ����
	tagVector2 operator-(const tagVector2& input) { return tagVector2(this->x - input.x, this->y - input.y); }

	// ����
	tagVector2 operator*(const tagVector2& input) { return tagVector2(this->x * input.x, this->y * input.y); }
	tagVector2 operator*(const int& input) { return tagVector2((float)input * this->x, (float)input * this->y); }
	tagVector2 operator*(const float& input) { return tagVector2(input * this->x, input * this->y); }
	tagVector2 operator*(const double& input) { return tagVector2((float)input * this->x, (float)input * this->y); }
	friend tagVector2 operator*(const int& input, tagVector2& v1) { return tagVector2((float)input * v1.x, (float)input * v1.y); }
	friend tagVector2 operator*(const float& input, tagVector2& v1) { return tagVector2(input * v1.x, input * v1.y); }
	friend tagVector2 operator*(const double& input, tagVector2& v1) { return tagVector2((float)input * v1.x, (float)input * v1.y); }

	// ��� ������
	tagVector2 operator+=(const tagVector2& input) { return (*this) = (*this) + input; }
	tagVector2 operator-=(const tagVector2& input) { return (*this) = (*this) - input; }
	tagVector2 operator*=(const tagVector2& input) { return (*this) = (*this) * input; }
	tagVector2 operator*=(const int& input) { return (*this) = (*this) * input; }
	tagVector2 operator*=(const float& input) { return (*this) = (*this) * input; }
	tagVector2 operator*=(const double& input) { return (*this) = (*this) * input; }

	// �� ������
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
		XMVECTOR temp = XMVectorSet(this->x, this->y, 0.f, 0.f);
		temp = XMVector2Normalize(temp);

		this->x = XMVectorGetX(temp);
		this->y = XMVectorGetY(temp);
	}

	float Get_Length()
	{
		XMVECTOR temp = XMVectorSet(this->x, this->y, 0.f, 0.f);
		temp = XMVector2Length(temp);

		return XMVectorGetX(temp);
	}

	float Get_Distance(const tagVector2& vDst)
	{
		XMVECTOR dst = XMVectorSet(vDst.x, vDst.y, 0.f, 0.f);
		XMVECTOR src = XMVectorSet(this->x, this->y, 0.f, 0.f);

		XMVECTOR result = dst - src;
		result = XMVector2Length(result);

		return XMVectorGetX(result);
	}

	float Get_Angle(const tagVector2& vDst)
	{
		XMVECTOR v1 = XMVectorSet(vDst.x, vDst.y, 0.f, 0.f);
		XMVECTOR v2 = XMVectorSet(this->x, this->y, 0.f, 0.f);

		XMVECTOR angle = XMVector2AngleBetweenVectors(v1, v2);
		float	angleRadians = XMVectorGetX(angle);

		return XMConvertToDegrees(angleRadians);
	}

	float Dot(const tagVector2& vDst)
	{
		XMVECTOR dst = XMVectorSet(vDst.x, vDst.y, 0.f, 0.f);
		XMVECTOR src = XMVectorSet(this->x, this->y, 0.f, 0.f);
		XMVECTOR result = XMVector2Dot(dst, src);
		return XMVectorGetX(result);
	}

	tagVector2 Cross_InputDst(const tagVector2& vDst)
	{
		XMVECTOR dst = XMVectorSet(vDst.x, vDst.y, 0.f, 0.f);
		XMVECTOR src = XMVectorSet(this->x, this->y, 0.f, 0.f);
		XMVECTOR result = XMVector2Cross(dst, src);

		return tagVector2(XMVectorGetX(result), XMVectorGetY(result));
	}

	tagVector2 Cross_InputSrc(const tagVector2& vSrc)
	{
		XMVECTOR dst = XMVectorSet(this->x, this->y, 0.f, 0.f);
		XMVECTOR src = XMVectorSet(vSrc.x, vSrc.y, 0.f, 0.f);
		XMVECTOR result = XMVector2Cross(dst, src);

		return tagVector2(XMVectorGetX(result), XMVectorGetY(result));
	}

	void Print() { cout << "x : " << this->x << "\t y : " << this->y << endl; }

}_vec2;

/*____________________________________________________________________
VECTOR3
______________________________________________________________________*/
typedef struct tagVector3 : public XMFLOAT3
{
	explicit tagVector3() : XMFLOAT3(0.f, 0.f, 0.f) {}
	explicit tagVector3(const float& x, const float& y, const float& z) : XMFLOAT3(x, y, z) {}
	explicit tagVector3(const float& input) : XMFLOAT3(input, input, input) {}
	explicit tagVector3(const XMFLOAT3& input) : XMFLOAT3(input) {}

	/*____________________________________________________________________
	������ �����ε�
	______________________________________________________________________*/
	// ����
	tagVector3 operator+(const tagVector3& input) { return tagVector3(this->x + input.x, this->y + input.y, this->z + input.z); }

	// ����
	tagVector3 operator-(const tagVector3& input) { return tagVector3(this->x - input.x, this->y - input.y, this->z - input.z); }

	// ����
	tagVector3 operator*(const tagVector3& input) { return tagVector3(this->x * input.x, this->y * input.y, this->z * input.z); }
	tagVector3 operator*(const int& input) { return tagVector3((float)input * this->x, (float)input * this->y, (float)input * this->z); }
	tagVector3 operator*(const float& input) { return tagVector3(input * this->x, input * this->y, input * this->z); }
	tagVector3 operator*(const double& input) { return tagVector3((float)input * this->x, (float)input * this->y, (float)input * this->z); }
	friend tagVector3 operator*(const int& input, tagVector3& v1) { return tagVector3((float)input * v1.x, (float)input * v1.y, (float)input * v1.z); }
	friend tagVector3 operator*(const float& input, tagVector3& v1) { return tagVector3(input * v1.x, input * v1.y, input * v1.z); }
	friend tagVector3 operator*(const double& input, tagVector3& v1) { return tagVector3((float)input * v1.x, (float)input * v1.y, (float)input * v1.z); }

	// ��� ������
	tagVector3 operator+=(const tagVector3& input) { return (*this) = (*this) + input; }
	tagVector3 operator-=(const tagVector3& input) { return (*this) = (*this) - input; }
	tagVector3 operator*=(const tagVector3& input) { return (*this) = (*this) * input; }
	tagVector3 operator*=(const int& input) { return (*this) = (*this) * input; }
	tagVector3 operator*=(const float& input) { return (*this) = (*this) * input; }
	tagVector3 operator*=(const double& input) { return (*this) = (*this) * input; }

	// �� ������
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
		XMVECTOR temp = XMVectorSet(this->x, this->y, this->z, 0.f);
		temp = XMVector3Normalize(temp);

		this->x = XMVectorGetX(temp);
		this->y = XMVectorGetY(temp);
		this->z = XMVectorGetZ(temp);
	}

	float Get_Length()
	{
		XMVECTOR temp = XMVectorSet(this->x, this->y, this->z, 0.f);
		temp = XMVector3Length(temp);

		return XMVectorGetX(temp);
	}

	float Get_Distance(const tagVector3& vDst)
	{
		XMVECTOR dst = XMVectorSet(vDst.x, vDst.y, vDst.z, 0.f);
		XMVECTOR src = XMVectorSet(this->x, this->y, this->z, 0.f);

		XMVECTOR result = dst - src;
		result = XMVector3Length(result);

		return XMVectorGetX(result);
	}

	float Get_Angle(const tagVector3& vDst)
	{
		XMVECTOR v1 = XMVectorSet(vDst.x, vDst.y, vDst.z, 0.f);
		XMVECTOR v2 = XMVectorSet(this->x, this->y, this->z, 0.f);

		XMVECTOR angle = XMVector3AngleBetweenVectors(v1, v2);
		float	angleRadians = XMVectorGetX(angle);

		return XMConvertToDegrees(angleRadians);
	}

	float Dot(const tagVector3& vDst)
	{
		XMVECTOR dst = XMVectorSet(vDst.x, vDst.y, vDst.z, 0.f);
		XMVECTOR src = XMVectorSet(this->x, this->y, this->z, 0.f);
		XMVECTOR result = XMVector3Dot(dst, src);
		return XMVectorGetX(result);
	}

	tagVector3 Cross_InputDst(const tagVector3& vDst)
	{
		XMVECTOR dst = XMVectorSet(vDst.x, vDst.y, vDst.z, 0.f);
		XMVECTOR src = XMVectorSet(this->x, this->y, this->z, 0.f);
		XMVECTOR result = XMVector3Cross(dst, src);

		return tagVector3(XMVectorGetX(result), XMVectorGetY(result), XMVectorGetZ(result));
	}

	tagVector3 Cross_InputSrc(const tagVector3& vSrc)
	{
		XMVECTOR dst = XMVectorSet(this->x, this->y, this->z, 0.f);
		XMVECTOR src = XMVectorSet(vSrc.x, vSrc.y, vSrc.z, 0.f);
		XMVECTOR result = XMVector3Cross(dst, src);

		return tagVector3(XMVectorGetX(result), XMVectorGetY(result), XMVectorGetZ(result));
	}

	void Print() { cout << "x : " << this->x << "\t y : " << this->y << "\t z : " << this->z << endl; }

}_vec3;

/*____________________________________________________________________
VECTOR4
______________________________________________________________________*/
typedef struct tagVector4 : public XMFLOAT4
{
	explicit tagVector4() : XMFLOAT4(0.f, 0.f, 0.f, 0.f) {}
	explicit tagVector4(const float& x, const float& y, const float& z, const float& w) : XMFLOAT4(x, y, z, w) {}
	explicit tagVector4(const float& input) : XMFLOAT4(input, input, input, input) {}
	explicit tagVector4(const XMFLOAT4& input) : XMFLOAT4(input) {}

	/*____________________________________________________________________
	������ �����ε�
	______________________________________________________________________*/
	// ����
	tagVector4 operator+(const tagVector4& input) { return tagVector4(this->x + input.x, this->y + input.y, this->z + input.z, this->w + input.w); }

	// ����
	tagVector4 operator-(const tagVector4& input) { return tagVector4(this->x - input.x, this->y - input.y, this->z - input.z, this->w - input.w); }

	// ����
	tagVector4 operator*(const tagVector4& input) { return tagVector4(this->x * input.x, this->y * input.y, this->z * input.z, this->w * input.w); }
	tagVector4 operator*(const int& input) { return tagVector4((float)input * this->x, (float)input * this->y, (float)input * this->z, (float)input * this->w); }
	tagVector4 operator*(const float& input) { return tagVector4(input * this->x, input * this->y, input * this->z, input * this->w); }
	tagVector4 operator*(const double& input) { return tagVector4((float)input * this->x, (float)input * this->y, (float)input * this->z, (float)input * this->w); }
	friend tagVector4 operator*(const int& input, tagVector4& v1) { return tagVector4((float)input * v1.x, (float)input * v1.y, (float)input * v1.z, (float)input * v1.w); }
	friend tagVector4 operator*(const float& input, tagVector4& v1) { return tagVector4(input * v1.x, input * v1.y, input * v1.z, input * v1.w); }
	friend tagVector4 operator*(const double& input, tagVector4& v1) { return tagVector4((float)input * v1.x, (float)input * v1.y, (float)input * v1.z, (float)input * v1.w); }

	// ��� ������
	tagVector4 operator+=(const tagVector4& input) { return (*this) = (*this) + input; }
	tagVector4 operator-=(const tagVector4& input) { return (*this) = (*this) - input; }
	tagVector4 operator*=(const tagVector4& input) { return (*this) = (*this) * input; }
	tagVector4 operator*=(const int& input) { return (*this) = (*this) * input; }
	tagVector4 operator*=(const float& input) { return (*this) = (*this) * input; }
	tagVector4 operator*=(const double& input) { return (*this) = (*this) * input; }

	// �� ������
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
		XMVECTOR temp = XMVectorSet(this->x, this->y, this->z, this->w);
		temp = XMVector4Normalize(temp);

		this->x = XMVectorGetX(temp);
		this->y = XMVectorGetY(temp);
		this->z = XMVectorGetZ(temp);
		this->w = XMVectorGetW(temp);
	}

	float Get_Length()
	{
		XMVECTOR temp = XMVectorSet(this->x, this->y, this->z, this->w);
		temp = XMVector4Length(temp);

		return XMVectorGetX(temp);
	}

	float Get_Distance(const tagVector4& vDst)
	{
		XMVECTOR dst = XMVectorSet(vDst.x, vDst.y, vDst.z, vDst.w);
		XMVECTOR src = XMVectorSet(this->x, this->y, this->z, this->w);

		XMVECTOR result = dst - src;
		result = XMVector4Length(result);

		return XMVectorGetX(result);
	}

	float Get_Angle(const tagVector4& vDst)
	{
		XMVECTOR v1 = XMVectorSet(this->x, this->y, this->z, this->w);
		XMVECTOR v2 = XMVectorSet(vDst.x, vDst.y, vDst.z, vDst.w);

		XMVECTOR angle = XMVector4AngleBetweenVectors(v1, v2);
		float	angleRadians = XMVectorGetX(angle);

		return XMConvertToDegrees(angleRadians);
	}

	float Dot(const tagVector4& vDst)
	{
		XMVECTOR dst = XMVectorSet(vDst.x, vDst.y, vDst.z, vDst.w);
		XMVECTOR src = XMVectorSet(this->x, this->y, this->z, this->w);
		XMVECTOR result = XMVector4Dot(dst, src);
		return XMVectorGetX(result);
	}

	tagVector4 Cross_Input_V1_V2(const tagVector4& v1, const tagVector4& v2)
	{
		XMVECTOR V1 = XMVectorSet(v1.x, v1.y, v1.z, v1.w);
		XMVECTOR V2 = XMVectorSet(v2.x, v2.y, v2.z, v2.w);
		XMVECTOR V3 = XMVectorSet(this->x, this->y, this->z, this->w);
		XMVECTOR result = XMVector4Cross(V1, V2, V3);

		return tagVector4(XMVectorGetX(result), XMVectorGetY(result), XMVectorGetZ(result), XMVectorGetW(result));
	}

	tagVector4 Cross_Input_V2_V3(const tagVector4& v2, const tagVector4& v3)
	{
		XMVECTOR V1 = XMVectorSet(this->x, this->y, this->z, this->w);
		XMVECTOR V2 = XMVectorSet(v2.x, v2.y, v2.z, v2.w);
		XMVECTOR V3 = XMVectorSet(v3.x, v3.y, v3.z, v3.w);
		XMVECTOR result = XMVector4Cross(V1, V2, V3);

		return tagVector4(XMVectorGetX(result), XMVectorGetY(result), XMVectorGetZ(result), XMVectorGetW(result));
	}

	tagVector4 Cross_Input_V1_V3(const tagVector4& v1, const tagVector4& v3)
	{
		XMVECTOR V1 = XMVectorSet(v1.x, v1.y, v1.z, v1.w);
		XMVECTOR V2 = XMVectorSet(this->x, this->y, this->z, this->w);
		XMVECTOR V3 = XMVectorSet(v3.x, v3.y, v3.z, v3.w);
		XMVECTOR result = XMVector4Cross(V1, V2, V3);

		return tagVector4(XMVectorGetX(result), XMVectorGetY(result), XMVectorGetZ(result), XMVectorGetW(result));
	}

	void Print() { cout << "x : " << this->x << "\t y : " << this->y << "\t z : " << this->z << "\t w : " << this->w << endl; }

}_vec4;


namespace Engine
{


	//typedef struct tagVertexColor
	//{
	//	D3DXVECTOR3			vPos;	 
	//	DWORD				dwColor;

	//}VTXCOL;

	//const DWORD		VTXFVF_COL = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX0;

	//typedef struct tagVertpexTexture
	//{
	//	D3DXVECTOR3			vPos;
	//	D3DXVECTOR3			vNormal;
	//	D3DXVECTOR2			vTex;

	//}VTXTEX;

	//const DWORD		VTXFVF_TEX = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1;

	//typedef	struct tagVertexCube
	//{
	//	D3DXVECTOR3		vPos;
	//	D3DXVECTOR3		vTex;

	//}VTXCUBE;

	//const DWORD		VTXFVF_CUBE = D3DFVF_XYZ | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE3(0);

	//typedef	struct	tagIndex16 
	//{
	//	WORD		_1, _2, _3;

	//}INDEX16;

	//typedef	struct	tagIndex32
	//{
	//	DWORD		_1, _2, _3;

	//}INDEX32;

	//

	///*____________________________________________________________________
	//RenderTarget Debug ��¿� ����ü ����.
	//______________________________________________________________________*/
	//typedef struct tagVertex_Screen
	//{
	//	_vec4	vPos;
	//	_vec2	vTex;

	//}VTXSCREEN;

	//const DWORD	VTXFVF_SCREEN = D3DFVF_XYZRHW | D3DFVF_TEX1;


	///*____________________________________________________________________
	//DynamicMesh �ִϸ��̼� ����ü ������.
	//______________________________________________________________________*/
	//typedef struct D3DXFRAME_DERIVED : public D3DXFRAME
	//{
	//	_matrix			CombinedTransformMatrix;

	//}D3DXFRAME_DERIVED;

	//typedef struct D3DXMESHCONTAINER_DERIVED : public D3DXMESHCONTAINER
	//{
	//	LPDIRECT3DTEXTURE9*		ppTexture;

	//	LPD3DXMESH				pOriMesh; // ������ ���¸� ������ �ִ� �޽�(���� �Һ�)

	//	_ulong					dwNumBones; 

	//	_matrix*				pFrameOffsetMatrix;
	//	// ���� �迭�� �Ҵ��ؼ� ���� ���� ����� �����Ѵ�.
	//	// �ִϸ��̼��� ������ ���·� �������� �� �� ���ʿ� ������� ������ �ִ� ���	

	//	_matrix**				ppFrameCombinedMatrix;
	//	// ������ ������ �ִ� CombinedTransformMatrix�� ��� ���ŵǱ� ������
	//	// �ƿ� �� �ּҵ��� ���� �����ؼ� �Ź� ���ŵ� ������ ��� ����� �������� ������ ������

	//	_matrix*				pRenderingMatrix;	// ������ ���� ���������� ����� ��� ���¸� �����ϴ� ������
	//
	//}D3DXMESHCONTAINER_DERIVED;

}


#endif // Engine_Struct_h__