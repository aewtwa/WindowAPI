#pragma once
#include "CObject.h"

class CTexture;

class CMonster :
    public CObject
{
private:
    Vec2        m_vCenterPos;
    float       m_fSpeed;
    float       m_fMaxDistance;
    int         m_iDir; // 1, -1
    CTexture*   m_pTex;

public:
    CMonster();
    ~CMonster();

    CLONE(CMonster);
    virtual void update();
    virtual void render(HDC _dc);

    float GetSpeed() { return m_fSpeed; }

    void SetSpeed(float _f) { m_fSpeed = _f; }
    void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }

    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisionEnter(CCollider* _pOther);
    virtual void OnCollisionExit(CCollider* _pOther);
};

