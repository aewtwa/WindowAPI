#include "pch.h"
#include "func.h"

#include "CEventMgr.h"

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup)
{
	tEvent event = {};
	event.eEvent = EVENT_TYPE::CREATE_OBJECT;
	event.lParam = (DWORD_PTR)_pObj;
	event.wParam = (DWORD_PTR)_eGroup;

	CEventMgr::GetInst()->AddEvent(event);
}

void DeleteObject(CObject* _pObj)
{
	tEvent event = {};
	event.eEvent = EVENT_TYPE::DELETE_OBJECT;
	event.lParam = (DWORD_PTR)_pObj;

	CEventMgr::GetInst()->AddEvent(event);
}

void ChangeScene(SCENE_TYPE _eNext)
{
	tEvent event = {};
	event.eEvent = EVENT_TYPE::SCENE_CHANGE;
	event.lParam = (DWORD_PTR)_eNext;

	CEventMgr::GetInst()->AddEvent(event);
}