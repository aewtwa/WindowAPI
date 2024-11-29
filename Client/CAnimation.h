#pragma once

class CAnimator;

class CAnimation
{
private:
	wstring		m_strName;
	CAnimator*	m_pAnimator;
	
public:
	CAnimation();
	~CAnimation();

	void update();
	void render(HDC _dc);

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	friend class CAnimator;
};