#ifndef Engine_Macro_h__
#define Engine_Macro_h__

namespace Engine
{
	#define			WINSIZEX 1600
	#define			WINSIZEY 900

	#define			MIN_STR	64
	#define			MAX_STR	256

	#define			USING(NAMESPACE)	using namespace NAMESPACE;

	#define			MSGERR_BOX(_message)			MessageBoxW(NULL, _message, L"System Message", MB_OK)
	#define			TAGMSGERR_BOX(_tag,_message)	MessageBoxW(NULL, TEXT(_message), _tag, MB_OK)

	#define			BEGIN(NAMESPACE)		namespace NAMESPACE {
	#define			END						}

	#ifdef ENGINE_EXPORTS
	#define ENGINE_DLL _declspec(dllexport)
	#else
	#define ENGINE_DLL _declspec(dllimport)
	#endif // ENGINE_EXPORTS

	#define NULL_CHECK( _ptr)	\
	{if( _ptr == 0){__debugbreak();return;}}
	
	#define NULL_CHECK_RETURN( _ptr, _return)	\
	{if( _ptr == 0){__debugbreak();return _return;}}
	
	#define NULL_CHECK_MSG( _ptr, _message )		\
	{if( _ptr == 0){MessageBox(NULL, _message, L"System Message",MB_OK);__debugbreak();}}
	
	#define NULL_CHECK_RETURN_MSG( _ptr, _return, _message )	\
	{if( _ptr == 0){MessageBox(NULL, _message, L"System Message",MB_OK);__debugbreak();return _return;}}
	
	
	#define FAILED_CHECK(_hr)	if( ((HRESULT)(_hr)) < 0 )	\
	{ MessageBoxW(NULL, L"Failed", L"System Error",MB_OK); __debugbreak(); return E_FAIL;}
	
	#define FAILED_CHECK_RETURN(_hr, _return)	if( ((HRESULT)(_hr)) < 0 )		\
	{ MessageBoxW(NULL, L"Failed", L"System Error",MB_OK); __debugbreak(); return _return;}
	
	#define FAILED_CHECK_MSG( _hr, _message)	if( ((HRESULT)(_hr)) < 0 )	\
	{ MessageBoxW(NULL, _message, L"System Message",MB_OK); __debugbreak();return E_FAIL;}
	
	#define FAILED_CHECK_RETURN_MSG( _hr, _return, _message)	if( ((HRESULT)(_hr)) < 0 )	\
	{ MessageBoxW(NULL, _message, L"System Message",MB_OK); __debugbreak();return _return;}
}

#define NO_COPY(CLASSNAME)								\
private:												\
CLASSNAME(const CLASSNAME&);							\
CLASSNAME& operator = (const CLASSNAME&);	

#define DECLARE_SINGLETON(CLASSNAME)					\
NO_COPY(CLASSNAME)										\
private:												\
	static CLASSNAME* m_pInstance;						\
public:													\
	static CLASSNAME* Get_Instance(void);				\
public:													\
	unsigned long Destroy_Instance(void);

#define IMPLEMENT_SINGLETON(CLASSNAME)					\
CLASSNAME* CLASSNAME::m_pInstance = nullptr;			\
CLASSNAME* CLASSNAME::Get_Instance(void)				\
{														\
	if(nullptr == m_pInstance)							\
	{													\
		m_pInstance = new CLASSNAME;					\
	}													\
	return m_pInstance;									\
}														\
unsigned long CLASSNAME::Destroy_Instance(void)			\
{														\
	unsigned long dwRefCnt = 0;							\
	if (nullptr != m_pInstance)							\
	{													\
		dwRefCnt = m_pInstance->Release();				\
		if (0 == dwRefCnt)								\
			m_pInstance = nullptr;						\
	}													\
	return dwRefCnt;									\
}


#define INIT_MATRIX			XMMatrixIdentity()
#define INIT_VEC2(input)	_vec2(input, input);
#define INIT_VEC3(input)	_vec3(input, input, input);
#define INIT_VEC4(input)	_vec4(input, input, input, input);

#endif // Engine_Macro_h__
