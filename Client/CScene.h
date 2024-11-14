#pragma once

// ���漱�� ������Ÿ�����θ� ��� ����
class CObject;

class CScene
{
private:
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END]; // ������Ʈ�� ���� �� ������ ���͸� �׷� ������ŭ ����
	wstring			 m_strName; // Scene �̸�

protected:
	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}

public:
	CScene();
	virtual ~CScene();

	void update();
	void render(HDC _dc);

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	virtual void Enter() = 0; // �ش� Scene�� ���� �� ȣ��
	virtual void Exit() = 0;  // �ش� Scene�� Ż�� �� ȣ��
};

