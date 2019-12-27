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
	//RenderTarget Debug 출력용 구조체 정의.
	//______________________________________________________________________*/
	//typedef struct tagVertex_Screen
	//{
	//	_vec4	vPos;
	//	_vec2	vTex;

	//}VTXSCREEN;

	//const DWORD	VTXFVF_SCREEN = D3DFVF_XYZRHW | D3DFVF_TEX1;


	///*____________________________________________________________________
	//DynamicMesh 애니메이션 구조체 재정의.
	//______________________________________________________________________*/
	//typedef struct D3DXFRAME_DERIVED : public D3DXFRAME
	//{
	//	_matrix			CombinedTransformMatrix;

	//}D3DXFRAME_DERIVED;

	//typedef struct D3DXMESHCONTAINER_DERIVED : public D3DXMESHCONTAINER
	//{
	//	LPDIRECT3DTEXTURE9*		ppTexture;

	//	LPD3DXMESH				pOriMesh; // 최초의 상태를 가지고 있는 메시(고정 불변)

	//	_ulong					dwNumBones; 

	//	_matrix*				pFrameOffsetMatrix;
	//	// 동적 배열로 할당해서 여러 개의 행렬을 보관한다.
	//	// 애니메이션을 포함한 형태로 렌더링을 할 때 최초에 뼈대들이 가지고 있는 행렬	

	//	_matrix**				ppFrameCombinedMatrix;
	//	// 뼈들이 가지고 있는 CombinedTransformMatrix는 계속 갱신되기 때문에
	//	// 아예 그 주소들을 따로 보관해서 매번 갱신된 정보를 얻어 사용할 목적으로 선언한 포인터

	//	_matrix*				pRenderingMatrix;	// 갱신이 끝난 최총적으로 출력할 행렬 상태를 보관하는 포인터
	//
	//}D3DXMESHCONTAINER_DERIVED;

}


#endif // Engine_Struct_h__
