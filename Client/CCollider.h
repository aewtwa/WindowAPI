#pragma once

class CObject;

class CCollider
{
private:
	CObject*	m_pOwner;		// collider�� �����ϰ� �ִ� ������Ʈ
	Vec2		m_vOffsetPos;	// ������Ʈ�κ��� ������� ��ġ
	Vec2		m_vFinalPos;	// finalupdate���� �� �����Ӹ��� ���

	Vec2		m_v;

public:
	CCollider();
	~CCollider();

	void finalupdate();

	friend class CObject;
};