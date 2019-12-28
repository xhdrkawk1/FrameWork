#pragma once

/*____________________________________________________________________
MathMgr
______________________________________________________________________*/
#define MatrixInverse(matrix)	Engine::CMathMgr::Get_Instance()->MatrixInverse(matrix)
#define TransformCoord(pOut, pVector, pMatrix)	Engine::CMathMgr::Get_Instance()->TransformCoord(pOut, pVector, pMatrix)
#define TransformNormal(pOut, pVector, pMatrix)	Engine::CMathMgr::Get_Instance()->TransformNormal(pOut, pVector, pMatrix)