#include "pch.h"
#include "CScene_Start.h"

#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"

#include "CCore.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	// Player Object �߰�
	CObject* pPlayerObj = new CPlayer;
	pPlayerObj->SetPos(Vec2(640.f, 384.f));
	pPlayerObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pPlayerObj, GROUP_TYPE::DEFAULT);

	// Monster Object �߰�
	Vec2 vResolution = CCore::GetInst()->GetResolution();

	CMonster* pMonsterObj = nullptr;
	for (int  i = 0; i < 5; ++i)
	{
		pMonsterObj = new CMonster;
		pMonsterObj->SetPos(Vec2(300.f + 100.f * i, 50.f));
		pMonsterObj->SetScale(Vec2(50.f, 50.f));
		pMonsterObj->SetCenterPos(Vec2(300.f + 100.f * i, 50.f));
		AddObject(pMonsterObj, GROUP_TYPE::DEFAULT);
	}
}
void CScene_Start::Exit()
{

}