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

	void CreateAnimation(CTexture* _pTex, Vec2 _vLT, );
	void FindAnimation();
	void Play();

	friend class CObject;
};