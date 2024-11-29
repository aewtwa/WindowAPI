#pragma once

class CObject;
class CAnimation;
class CTexture;

class CAnimator
{
private:
	CObject*					m_pOwner; // Animator ���� ������Ʈ
	map<wstring, CAnimation*>	m_mapAnim; // ��� Animation
	CAnimation*					m_pCurAnim; // ���� ������� Animation

public:
	CAnimator();
	~CAnimator();

	void update();
	void render(HDC _dc);

	void CreateAnimation(const wstring& _strName, CTexture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, UINT _iFrameCount);
	void FindAnimation();
	void Play();

	friend class CObject;
};