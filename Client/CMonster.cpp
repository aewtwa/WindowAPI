#include "pch.h"
#include "CMonster.h"

#include "CTimeMgr.h"
#include "CCollider.h"
#include "CPlayer.h"
#include "CResMgr.h"
#include "CTexture.h"

CMonster::CMonster()
	: m_vCenterPos(Vec2(0.f,0.f))
	, m_fSpeed(100.f)
	, m_fMaxDistance(100.f)
	, m_iDir(1)
	, m_pTex(nullptr)
{
	m_pTex = CResMgr::GetInst()->LoadTexture(L"MonsterTex", L"texture\\Monster.bmp");
	SetName(L"Monster");
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 40.f));
}

CMonster::~CMonster()
{
}

void CMonster::update()
{
	Vec2 vCurPos = GetPos();
	vCurPos.x += fDT * m_fSpeed * m_iDir;

	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;

	if (0.f < fDist)
	{
		m_iDir *= -1;
		vCurPos.x += fDist * m_iDir;
	}
	SetPos(vCurPos);
}

void CMonster::render(HDC _dc)
{
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();

	Vec2 vPos = GetPos();

	TransparentBlt(_dc
		, (int)(vPos.x - (float)(iWidth / 2))
		, (int)(vPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0, 255));

	// 컴포넌트(충돌체, etc...)가 있는 경우 렌더 
	component_render(_dc);
}

void CMonster::OnCollision(CCollider* _pOther)
{
}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player")
	{
		DeleteObject(this);
	}

	pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Missile")
	{
		DeleteObject(this);
	}
}

void CMonster::OnCollisionExit(CCollider* _pOther)
{
}