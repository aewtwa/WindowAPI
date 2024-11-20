#pragma once

class CObject;

class CCollider
{
private:
	static UINT	g_iNextID;

	CObject*	m_pOwner;		// collider�� �����ϰ� �ִ� ������Ʈ
	Vec2		m_vOffsetPos;	// ������Ʈ�κ��� ������� ��ġ
	Vec2		m_vFinalPos;	// finalupdate���� �� �����Ӹ��� ���
	Vec2		m_vScale; // �浹ü�� ũ��

	UINT		m_iID; // �浹ü ������ ID��
	int			m_iCol;

public:
	CCollider();
	CCollider(const CCollider& _origin);
	~CCollider();

	CCollider& operator = (CCollider& _origin) = delete;

	void finalupdate();
	void render(HDC _dc);

	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }
	Vec2 GetFinalPos() { return m_vFinalPos; }
	CObject* GetObj() { return m_pOwner; }
	UINT GetID() { return m_iID; }

	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	// �浹 ���� �Լ�
	void OnCollision(CCollider* _pOther); // �浹���� ��� ȣ��Ǵ� �Լ�
	void OnCollisionEnter(CCollider* _pOther); // ��� �� �ε��� ����
	void OnCollisionExit(CCollider* _pOther); // ��� �� �������� ����

	friend class CObject;
};