#pragma once

class CObject;
class CAnimation;
class CTexture;

class CAnimator
{
private:
	CObject*					m_pOwner; // Animator 소유 오브젝트
	map<wstring, CAnimation*>	m_mapAnim; // 모든 Animation
	CAnimation*					m_pCurAnim; // 현재 재생중인 Animation

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