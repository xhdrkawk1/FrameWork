#ifndef Engine_Struct_h__
#define Engine_Struct_h__

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
