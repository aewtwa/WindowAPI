#pragma once
#include "CObject.h"

class CTexture;

class CPlayer :
    public CObject
{
private:

public:
    CPlayer();
    ~CPlayer();

    CLONE(CPlayer);
    virtual void update();
    virtual void render(HDC _dc);

    void Fire();
};