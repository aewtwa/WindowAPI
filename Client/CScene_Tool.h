#pragma once
#include "CScene.h"

class CScene_Tool :
    public CScene
{
private:

public:
    CScene_Tool();
    ~CScene_Tool();

    virtual void update();
    virtual void Enter();
    virtual void Exit();
};

