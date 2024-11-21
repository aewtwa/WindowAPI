#pragma once

// 전방선언 포인터타입으로만 사용 가능
class CObject;

class CScene
{
private:
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END]; // 오브젝트를 저장 및 관리할 벡터를 그룹 개수만큼 선언
	wstring			 m_strName; // Scene 이름

public:
	CScene();
	virtual ~CScene();

	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _dc);

	const wstring& GetName() { return m_strName; }
	void SetName(const wstring& _strName) { m_strName = _strName; }

	virtual void Enter() = 0; // 해당 Scene에 진입 시 호출
	virtual void Exit() = 0;  // 해당 Scene을 탈출 시 호출

	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}
	const vector<CObject*>& GetGroupObject(GROUP_TYPE _eType) { return m_arrObj[(UINT)_eType]; }
	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteAll();
};

