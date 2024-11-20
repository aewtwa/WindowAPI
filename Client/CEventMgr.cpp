#include "pch.h"
#include "CEventMgr.h"

#include "CObject.h"
#include "CSceneMgr.h"
#include "CScene.h"

CEventMgr::CEventMgr()
{

}
CEventMgr::~CEventMgr()
{

}

void CEventMgr::update()
{
	// 이전프레임에서 등록해둔 Dead Object들을 삭제한다.
	for (size_t i = 0; i < m_vecDead.size(); i++)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();

	// Event 처리
	for (size_t i = 0; i < m_vecEvent.size(); i++)
	{
		Excute(m_vecEvent[i]);
	}

	m_vecEvent.clear();
}

void CEventMgr::Excute(const tEvent& _event)
{
	_event.eEvent;
	switch (_event.eEvent)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParam : Object Adress
		// wParam : Group Type
		CObject* pNewObj = (CObject*)_event.lParam;
		GROUP_TYPE eType = (GROUP_TYPE)_event.wParam;

		CSceneMgr::GetInst()->GetCurScene()->AddObject(pNewObj, eType);
	}
		break;

	case EVENT_TYPE::DELETE_OBJECT:
	{
		// lParam : Object Adress
		// Object를 Dead상태로 변경
		// 삭제예정 오브젝트들을 모아둔다.
		CObject* pDeadObj = (CObject*)_event.lParam;
		pDeadObj->SetDead();
		m_vecDead.push_back(pDeadObj);
	}

		break;

	case EVENT_TYPE::SCENE_CHANGE:

		break;
	}
}