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
#include "CAnimator.h"

CPlayer::CPlayer()
{
	// Texture 로딩하기
	//m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player.bmp");
	SetName(L"Player");

	CreateCollider();
	GetCollider()->SetScale(Vec2(100.f, 100.f));

	// Texture 로딩하기
	CTexture* pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Bazzi\\Bazzi.bmp");
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"WALK_DOWN", pTex, Vec2(0.f, 120.f), Vec2(50.f, 60.f), Vec2(50.f, 0.f), 0.1f, 4);
	GetAnimator()->Play(L"WALK_DOWN", true);
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
	GetAnimator()->update();
}

void CPlayer::render(HDC _dc)
{
	// 컴포넌트(충돌체, etc...)가 있는경우 렌더
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
