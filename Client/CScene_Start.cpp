#include "pch.h"
#include "CScene_Start.h"

#include "CPathMgr.h"

#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"

#include "CCore.h"

#include "CTexture.h"
#include "CCollisionMgr.h"
#include "CSceneMgr.h"
#include "CKeyMgr.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::update()
{
	CScene::update();

	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::TOOL);
	}
}

void CScene_Start::Enter()
{
	// Player Object 추가
	CObject* pPlayerObj = new CPlayer;
	pPlayerObj->SetPos(Vec2(640.f, 384.f));
	pPlayerObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pPlayerObj, GROUP_TYPE::PLAYER);

	//// 복제Player Object 추가
	//CObject* pOtherPlayer = pPlayerObj->Clone();
	//pOtherPlayer->SetPos(Vec2(840.f, 384.f));
	//AddObject(pOtherPlayer, GROUP_TYPE::PLAYER);

	// Monster Object 추가
	Vec2 vResolution = CCore::GetInst()->GetResolution();

	CMonster* pMonsterObj = nullptr;
	for (int i = 0; i < 5; ++i)
	{
		pMonsterObj = new CMonster;
		pMonsterObj->SetPos(Vec2(300.f + 100.f * i, 50.f));
		pMonsterObj->SetScale(Vec2(50.f, 50.f));
		pMonsterObj->SetCenterPos(Vec2(300.f + 100.f * i, 50.f));
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}

	// 충돌 지정
	// PLAYER그룹과 MONSTER그룹 간의 충돌체크
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::PROJ_PLAYER);
}

void CScene_Start::Exit()
{
	DeleteAll();

	CCollisionMgr::GetInst()->Reset();
}