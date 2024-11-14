#include "pch.h"
#include "CSceneMgr.h"

#include "CScene_Start.h"

CSceneMgr::CSceneMgr()
	: m_arrScene{}
	, m_pCurCene(nullptr)
{

}

CSceneMgr::~CSceneMgr()
{
	// 씬 전부 삭제
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (nullptr != m_arrScene[i])
			delete m_arrScene[i];
	}
}

void CSceneMgr::init()
{
	// Scene 생성
	m_arrScene[(UINT)SCENE_TYPE::START] = new CScene_Start;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start_Scene");

	// 현재 씬 설정
	m_pCurCene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurCene->Enter();
}

void CSceneMgr::update()
{
	m_pCurCene->update();
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurCene->render(_dc);
}