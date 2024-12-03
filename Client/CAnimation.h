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
	CTexture*			m_pTex; // Animation�� ����ϴ� �ؽ���
	vector<tAnimFrm>	m_vecFrm; // ��� ������ ����
	int					m_iCurFrm; // ���� ������
	float				m_fAccTime; // �ð� ����
	bool				m_bFinish; // ��� �� ���޿���

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