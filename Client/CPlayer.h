#pragma once
#include "CObject.h"

class CTexture;

class CPlayer :
    public CObject
{
private:
    CTexture*   m_pTex;

public:
    CPlayer();
    ~CPlayer();

    virtual void update();
    virtual void render(HDC _dc);
};