#pragma once
#include "cocos2d.h"
#include "Scene2.h"
#include "Scene3.h"
#include "Scene1.h"

class LoseScene : public cocos2d::Scene
{
    private:
    static int current;
public:
  //  
    static cocos2d::Scene* createScene();
    void setCurrent(int n);
    int getCurrent();
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(LoseScene);
};
