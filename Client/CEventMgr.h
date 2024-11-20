#pragma once
struct tEvent
{
	EVENT_TYPE	eEvent;
	DWORD_PTR	lParam;
	DWORD_PTR	wParam;
};
class CEventMgr
{
	SINGLE(CEventMgr)
private:
	vector<tEvent>		m_vecEvent;
	vector<CObject*>	m_vecDead;

public:
	void update();

	void AddEvent(const tEvent& _event) { m_vecEvent.push_back(_event); }

private:
	void Excute(const tEvent& _event);
};