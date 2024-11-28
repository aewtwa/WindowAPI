#pragma once
#include "CObject.h"

class CTexture;

class CMissile :
    public CObject
{
private:
    CTexture*   m_pTex;
    float       m_fTheta;
    float       m_fSpeed;
    Vec2        m_vDir;


public:
    CMissile();
    ~CMissile();

    CLONE(CMissile);
    virtual void update();
    virtual void render(HDC _dc);

    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisionEnter(CCollider* _pOther);
    virtual void OnCollisionExit(CCollider* _pOther);

    void SetDir(float _fTheta) { m_fTheta = _fTheta; }
    void SetDir(Vec2 _vDir) 
    { 
        m_vDir = _vDir;
        m_vDir.Normalize();
    }
};

