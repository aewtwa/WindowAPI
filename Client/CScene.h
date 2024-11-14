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

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }
};

