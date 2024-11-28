#include "pch.h"
#include "CMissile.h"

#include "CResMgr.h"
#include "CCollider.h"
#include "CTexture.h"
#include "CTimeMgr.h"

CMissile::CMissile()
	: m_pTex(nullptr)
	, m_fTheta(PI / 4.f)
	, m_fSpeed(600.f)
	, m_vDir(Vec2(1.f,1.f))
{
	m_vDir.Normalize();
	SetName(L"Missile");
	m_pTex = CResMgr::GetInst()->LoadTexture(L"MissileTex", L"texture\\Missile.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2(30.f, 30.f));
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	Vec2 vPos = GetPos();

	vPos.x += m_fSpeed * m_vDir.x * fDT;
	vPos.y += m_fSpeed * m_vDir.y * fDT;

	SetPos(vPos);
}

void CMissile::render(HDC _dc)
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

void CMissile::OnCollision(CCollider* _pOther)
{
}

void CMissile::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Monster")
	{
		DeleteObject(this);
	}
}

void CMissile::OnCollisionExit(CCollider* _pOther)
{
}
