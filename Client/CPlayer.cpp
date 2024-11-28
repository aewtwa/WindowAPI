#include "pch.h"
#include "CPlayer.h"

#include "CScene.h"
#include "CMissile.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CSceneMgr.h"
#include "CPathMgr.h"
#include "CResMgr.h"
#include "CTexture.h"
#include "CMonster.h"
#include "CCollider.h"

CPlayer::CPlayer()
	: m_pTex(nullptr)
{
	SetName(L"Player");
	// Texture 로딩하기
	m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(100.f, 100.f));
}

CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	Vec2 vPos = GetPos();

	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 200.f * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 200.f * fDT;
	}
	if (KEY_TAP(KEY::LClick))
	{
		Fire();
	}


	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
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

void CPlayer::Fire()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	// Missile Object
	CMissile* Missile = new CMissile;
	Missile->SetPos(vMissilePos);
	Missile->SetScale(Vec2(50.f, 50.f));
	Missile->SetDir(Vec2(-1.f,-7.f));

	CreateObject(Missile, GROUP_TYPE::PROJ_PLAYER);
}
