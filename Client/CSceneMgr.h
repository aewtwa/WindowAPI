#pragma once

class CScene;

class CSceneMgr
{
	SINGLE(CSceneMgr);
private:
	CScene*		m_arrScene[(UINT)SCENE_TYPE::END]; // ��� �� ���
	CScene*		m_pCurCene; // ���� ��
public:
	void init();
};

