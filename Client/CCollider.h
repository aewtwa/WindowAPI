#pragma once

class CObject;

class CCollider
{
private:
	CObject*	m_pOwner;		// collider�� �����ϰ� �ִ� ������Ʈ
	Vec2		m_vOffsetPos;	// ������Ʈ�κ��� ������� ��ġ
	Vec2		m_vFinalPos;	// finalupdate���� �� �����Ӹ��� ���
	Vec2		m_vScale; // �浹ü�� ũ��


public:
	CCollider();
	~CCollider();

	void finalupdate();
	void render(HDC _dc);

	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }

	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	friend class CObject;
};