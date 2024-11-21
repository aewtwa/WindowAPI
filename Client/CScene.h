#pragma once

// ���漱�� ������Ÿ�����θ� ��� ����
class CObject;

class CScene
{
private:
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END]; // ������Ʈ�� ���� �� ������ ���͸� �׷� ������ŭ ����
	wstring			 m_strName; // Scene �̸�

public:
	CScene();
	virtual ~CScene();

	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _dc);

	const wstring& GetName() { return m_strName; }
	void SetName(const wstring& _strName) { m_strName = _strName; }

	virtual void Enter() = 0; // �ش� Scene�� ���� �� ȣ��
	virtual void Exit() = 0;  // �ش� Scene�� Ż�� �� ȣ��

	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}
	const vector<CObject*>& GetGroupObject(GROUP_TYPE _eType) { return m_arrObj[(UINT)_eType]; }
	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteAll();
};

