#pragma once

class CAnimator;
class CTexture;

struct tAnimFrm
{
	Vec2	vLT;
	Vec2	vSlice;
	float	fDuration;
};

class CAnimation
{
private:
	wstring				m_strName;
	CAnimator*			m_pAnimator;
	CTexture*			m_pTex; // Animation이 사용하는 텍스쳐
	vector<tAnimFrm>	m_vecFrm; // 모든 프레임 정보
	int					m_iCurFrm; // 현재 프레임
	float				m_fAccTime; // 시간 누적
	bool				m_bFinish; // 재생 끝 도달여부

public:
	CAnimation();
	~CAnimation();

	void update();
	void render(HDC _dc);

	const wstring& GetName() { return m_strName; }

	void Create(CTexture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, float _fDuration, UINT _iFrameCount);

	bool IsFinish() { return m_bFinish; }
	void SetFrame(int _iFrameIdx);

private:
	void SetName(const wstring& _strName) { m_strName = _strName; }

	friend class CAnimator;
};