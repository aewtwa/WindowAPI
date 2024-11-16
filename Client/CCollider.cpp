#include "pch.h"
#include "CCollider.h"

#include "CObject.h"

CCollider::CCollider()
	: m_pOwner(nullptr)
	, m_vOffsetPos{}
	, m_vFinalPos{}
{
}

CCollider::~CCollider()
{
}

void CCollider::finalupdate()
{
	// Object�� ��ġ�� ���󰣴�.
	Vec2 vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;
}
